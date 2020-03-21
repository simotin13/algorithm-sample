#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sort.h"
void make_random_ary(int *ary, int len, int disable_duplicate) {
    int i;
    int val;
	int *pAry = malloc(sizeof(int) * VAL_MAX);

	memset(pAry, 0, sizeof(int) * VAL_MAX);

    srand(13);

    for (i = 0; i < ARY_SIZE; i++) {
        val = rand() % VAL_MAX;
        if (disable_duplicate == 1) {
            while(pAry[val] != 0) {
                val = rand() % VAL_MAX;
            }
            pAry[val] = 1;
        }
        ary[i] = val;
    }
    return;
}

int binary_search(int *ary, int len, int val) {
    int pos;
    int result;
    int min, max;

    result = -1;
    pos = len / 2;
    min = 0;
    max = len -1;
    while(1) {
        if (ary[pos] == val) {
            result = pos;
        }

        if ((pos <= min) || ((max) <= pos)) {
            break;
        }

        if (ary[pos] <= val) {
            min = pos;
            pos = ((len - pos) / 2) + pos;
        } else {
            max = pos;
            pos /= 2;
        }
    }

    return result;
}

void dump_ary(int *ary, int len) {
    int i;
    fprintf(stdout, "len:[%d] ",len);
    for (i = 0; i < len; i++) {
        fprintf(stdout, "%d ", ary[i]);
    }
    fprintf(stdout, "\n");
}

void insertion_sort(int *ary,int len) {
    int i, j;
    int tmp;
    for (i = 1; i < len; i++) {
        j = i;
        while(1 <= j) {
            if (ary[j] < ary[j - 1]) {
                tmp = ary[j-1];
                ary[j-1] = ary[j];
                ary[j] = tmp;
            } else {
                break;
            }
            j--;
        }
    }
}

void selection_sort(int *ary,int len) {
    int i,j;
    int min_pos;
    int tmp;
    for(i = 0; i < len; i++) {
        min_pos = i;
        for(j = i+1; j < len; j++) {
            if (ary[j] < ary[min_pos]) {
                min_pos = j;
            }
        }
        tmp = ary[i];
        ary[i] = ary[min_pos];
        ary[min_pos] = tmp;
    }
}

void bubble_sort(int *ary, int len) {
    int i,j,tmp;
    for (i = 0; i < len-1; i++) {   
        for(j = 0; j < len-1; j++) {
            if (ary[j+1] < ary[j]) {
                tmp = ary[j];
                ary[j] = ary[j+1];
                ary[j+1] = tmp;
            }
        }
    }
}

void quick_sort(int *ary, int len) {
    int pivot;
    int min;
    int max;
    int tmp;

    if (len < 2 ) {
        return;
    }
    pivot = len-1;
    min = 0;
    max = len-2;
    while(min < max) {
        while(min < max) {
            if (ary[pivot] < ary[min]) {
                break;
            }
            min++;
        }
        while(min < max) {
            if (ary[max] < ary[pivot]) {
                break;
            }
            max--;
        }

        if (min == max) {
            break;
        }

        tmp = ary[min];
        ary[min] = ary[max];
        ary[max] = tmp;
        min++;
        max--;
    }

    if (ary[pivot] < ary[min]) {
        tmp = ary[pivot];
        ary[pivot] = ary[min];
        ary[min] = tmp;
    }
    quick_sort(&ary[0], min+1);
    quick_sort(&ary[min+1], len-min-1);
    return;
}

void bucket_sort(int *ary, int len) {
    int i;
    int buf[VAL_MAX];

    memset(buf, -1, sizeof(int) * VAL_MAX);

    for(i = 0; i < len; i++) {
        buf[ ary[i] ] = ary[i];
    }

    int pos = 0;
    for(i = 0; i < VAL_MAX; i++) {
        if (buf[i] != -1) {
            ary[pos] = buf[i];
            pos++;
        }

        if (len <= pos) {
            break;
        }
    }
}

// ���z�����グ�\�[�g
#define COUNT_RANGE (VAL_MAX+1)
static int count[COUNT_RANGE];
void counting_sort(int *ary, int n) {
    int  i;
    int val,val_idx;
    int tmp[ARY_SIZE];

    for (i = 0; i <= ARY_SIZE; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        count[ ary[i] ]++;
        tmp[i] = ary[i];
    }

    // �����グ���L�[�̗ݐϓx�����z
    for (i = 0; i < COUNT_RANGE; i++) {
        count[i+1] += count[i];
    }

	// �ݐϓx�̑傫�����ɒl�������Ă������߁A
	// �z��̌�납�珇�ԂɃ\�[�g���Ă����Ȃ��ƁA����\�[�g�ɂȂ�Ȃ�
	// ���Ɋ�\�[�g�Ŏg�p����ꍇ�͈���\�[�g�ł���K�v������̂Œ���
    for (i = n - 1; 0 <= n; i--) {
        // �\�[�g�Ώۂ̒l���擾
        val = tmp[i];
        // �\�[�g�O�ɗݐϓx�������炷
        count[val]--;

        // �z��̒l�ɑΉ�����ݐϓx�����\�[�g�ς݂̃C���f�b�N�X�ɂȂ�
        val_idx = count[val];
        ary[val_idx] = tmp[i];
    }
    return;
}

#define MASK_VAL	(0xFF)
void radix_sort(int *ary, int len) {
	int i;
	int bit;
	int bits_max = 64;	// 32bit�܂őΉ��Ƃ���
	int val;
	int count[256];
	int tmp[ARY_SIZE];
	int pos;

	for(bit = 0; bit < bits_max; bit += 8) {
		memset(count, 0, sizeof(int) * 256);

		for (i = 0; i < len; i++) {
			val = (ary[i] >> bit) & MASK_VAL;
			count[ val ]++;
			tmp[i] = ary[i];
		}

		for (i = 0; i < 255; i++) {
			count[ i + 1 ] += count[i];
		}

		for (i = len - 1; 0 <= i; i--) {
			// �\�[�g�Ώۂ̒l���擾
			// �����̒l�̓t�B���^�����L�[�̒l�Ŕ�r����K�v������
			val = (tmp[i] >> bit) & MASK_VAL;

			fprintf(stdout, "val:[%d], count[%d]:%d\n", val, val, count[val]);
			// �\�[�g�O�ɗݐϒl�����炷
			count[val]--;

			// �ݐϒl��������C���f�b�N�X�l���擾
			pos = count[val];
			ary[pos] = tmp[i];
		}

		fprintf(stdout, "ary ");
		dump_ary(ary, len);
		fprintf(stdout, "\n");
	}

	return;
}
