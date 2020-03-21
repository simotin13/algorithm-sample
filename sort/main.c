#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

int main(int argc, char **argv) {
    int i;
    int ary[ARY_SIZE];
    time_t start,end;

    srand(100);
    for (i = 0; i < ARY_SIZE; i++) {
        ary[i] = rand() % VAL_MAX;
    }

    fprintf(stdout, "-------- before sort -------\n");
    dump_ary(ary, ARY_SIZE);
    fprintf(stdout, "----------------------------\n\n");

    // =========================================================================
    // ソート実行
    // =========================================================================
    start = time(NULL);
    bucket_sort(ary, ARY_SIZE);
    end = time(NULL);

    fprintf(stdout, "bucket_sort:[%d] sec\n", (int)(end - start));
    fprintf(stdout, "-------- after sort -------\n");
    dump_ary(ary, ARY_SIZE);
    fprintf(stdout, "---------------------------\n\n");

    return 0;
}
