#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sort.h"

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

// 分布数え上げソート
#define COUNT_RANGE	(VAL_MAX+1)
static int count[COUNT_RANGE];    // 入力の範囲は 0～VAL_MAXまで
void count_sort(int *ary, int n)
{
    int  i;
    int pos;
    int tmp[ARY_SIZE];

    for (i = 0; i <= COUNT_RANGE; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        count[ ary[i] ]++;
        tmp[i] = ary[i];
    }

    for (i = 0; i < COUNT_RANGE; i++) {
        count[i+1] += count[i];
    }

    // 最後の要素から順番に見ていく
    for (i = n - 1; i >= 0; i--) {
        // 頻度分布から元の配列のインデックスを取得
        pos = count[ tmp[i] ];
        count[ tmp[i] ]--;

        // 元の配列の値を変更
        ary[ pos ] = tmp[i];
    }

    return;
}
