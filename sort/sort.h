#ifndef _SORT_H_
#define _SORT_H_

// =============================================================================
// define
// =============================================================================
#define VAL_MAX     (100)                 // 比較によらないソートによる値の最大
#define ARY_SIZE    (32)                    // ソート対象の配列サイズ

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
extern void radix_sort(int *ary, int len);
#endif
