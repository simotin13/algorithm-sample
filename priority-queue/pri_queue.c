// priority queue(max heap)
// ref. https://programming-place.net/ppp/contents/algorithm/data_struct/009.html#binary_heap

#include <stdio.h>
#define HEAP_SIZE	16
int empty_pos = 1;
int heap[HEAP_SIZE];

int init_queue(void)
{
	int i;

	for(i = 0; i < HEAP_SIZE; i++)
	{
		heap[i] = -1;
	}

	return 0;
}

int enqueue(int val)
{
	int parent_pos, cur_pos;
	int tmp;
	heap[empty_pos] = val;

	cur_pos = empty_pos;

	parent_pos = cur_pos / 2;
	while(0 < parent_pos)
	{
		if (heap[parent_pos] < val)
		{
			tmp = heap[parent_pos];
			heap[parent_pos] = val;
			heap[cur_pos] = tmp;
			cur_pos = parent_pos;
			parent_pos = cur_pos / 2;
		}
		else
		{
			break;
		}
	}

	empty_pos++;

	return 0;
}

int dequeue(int *pVal)
{
	int cur_pos = 1;
	int tmp;
	int tmp_pos, left_pos, right_pos;

	*pVal = heap[1];
	empty_pos--;
	heap[cur_pos] = heap[empty_pos];
	heap[empty_pos] = -1;

	while(cur_pos < empty_pos)
	{
		left_pos = cur_pos * 2;
		right_pos = cur_pos * 2 + 1;
		if (heap[left_pos] < heap[right_pos])
		{
			tmp_pos = right_pos;
		}
		else
		{
			tmp_pos = left_pos;
		}
		if (heap[tmp_pos] < heap[cur_pos])
		{
			break;
		}
		else
		{
			tmp = heap[tmp_pos];
			heap[tmp_pos] = heap[cur_pos];
			heap[cur_pos] = tmp;
			cur_pos = tmp_pos;
		}
	}

	return 0;
}

void dump_queue(void)
{
	int i;

	for(i = 0; i < HEAP_SIZE; i++)
	{
		fprintf(stdout, " %d", heap[i]);
	}

	fprintf(stdout, "\n");
}
