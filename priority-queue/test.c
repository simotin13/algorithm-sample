#include <assert.h>
#include <stdio.h>
#include "pri_queue.h"

int main(int argc, char **argv)
{
    int val;
    init_queue();

    enqueue(10);
    enqueue(2);
    enqueue(5);
    enqueue(4);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(1);

    dump_queue();

    dequeue(&val);
    assert(val == 10);
    dequeue(&val);
    assert(val == 10);
    dequeue(&val);
    assert(val == 9);
    dequeue(&val);
    assert(val == 8);
    dequeue(&val);
    assert(val == 7);
    dequeue(&val);
    assert(val == 6);
    dequeue(&val);
    assert(val == 5);
    dequeue(&val);
    assert(val == 4);
    dequeue(&val);
    assert(val == 2);
    dequeue(&val);
    assert(val == 1);
    return 0;
}