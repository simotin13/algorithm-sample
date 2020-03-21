#ifndef _SORT_H_
#define _SORT_H_

// =============================================================================
// define
// =============================================================================
#define VAL_MAX     (10)                  // ��r�ɂ��Ȃ��\�[�g�ɂ��l�̍ő�
#define ARY_SIZE    (10)                    // �\�[�g�Ώۂ̔z��T�C�Y

// =============================================================================
// util
// =============================================================================
void make_random_ary(int *ary, int len, int disable_duplicate);
extern void dump_ary(int *ary, int len);

// =============================================================================
// search
// =============================================================================
extern int binary_search(int *ary, int len, int val);

// =============================================================================
// sort
// =============================================================================
extern void insertion_sort(int *ary,int len);
extern void selection_sort(int *ary,int len);
extern void bubble_sort(int *ary, int len);
extern void quick_sort(int *ary, int len);
extern void bucket_sort(int *ary, int len);
extern void counting_sort(int *ary, int len);

#endif