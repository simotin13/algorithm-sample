#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

int main(int argc, char **argv) {
    int i;
    int ary[ARY_SIZE];
    time_t start,end;

	make_random_ary(ary, ARY_SIZE, 0);
    fprintf(stdout, "-------- before sort -------\n");
    dump_ary(ary, ARY_SIZE);
    fprintf(stdout, "----------------------------\n\n");

    // =========================================================================
    // execute sort
    // =========================================================================
    start = time(NULL);
    counting_sort(ary, ARY_SIZE);
    end = time(NULL);

    fprintf(stdout, "bucket_sort:[%d] sec\n\n", (int)(end - start));
    fprintf(stdout, "-------- after sort -------\n");
    dump_ary(ary, ARY_SIZE);
    fprintf(stdout, "---------------------------\n\n");

    return 0;
}
