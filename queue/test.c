
#include "queue.h"

typedef struct node
{
	int id;
} node;

int indata(void **data)
{
	node **p = (node **)data;
	*p = (node *)malloc(sizeof(node));
	if (*p == NULL) return -1;		// -->

	int id;
	scanf("%d", &id);
	(*p)->id = id;

	return 0;
}

void outdata(const void *data)
{
	node *p = (node *)data;
	printf("%d ", p->id);
}

int main(void)
{
	queue q;

	create_queue(&q);
	insert_queue(&q, indata);
	list_queue(&q, outdata);
	insert_queue(&q, indata);
	list_queue(&q, outdata);
	insert_queue(&q, indata);
	list_queue(&q, outdata);
	remove_queue(&q, NULL);
	list_queue(&q, outdata);
	remove_queue(&q, NULL);
	list_queue(&q, outdata);
	remove_queue(&q, NULL);
	list_queue(&q, outdata);

	return 0;
}
