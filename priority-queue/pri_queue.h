#ifndef _PRI_QUEUE_
#define _PRI_QUEUE_

int init_queue(void);
int enqueue(int val);
int dequeue(int *pVal);
void dump_queue(void);

#endif // _PRI_QUEUE_