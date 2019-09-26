
#include "link.h"

typedef struct node
{
	int data;
} node;

int indata(void **pointer)
{
	node **p = (node **)pointer;
	*p = (node *)malloc(sizeof(node));
	if (*p == NULL) return -1;		// -->

	int data;
	scanf("%d", &data);
	(*p)->data = data;

	return 0;
}

void outdata(const void *pointer)
{
	node *p = (node *)pointer;
	printf("%d ", p->data);
}

int main(void)
{
	link l;

	create_link(&l);
	insert_link(l, 0, indata);
	list_link(l, outdata);
	insert_link(l, 1, indata);
	list_link(l, outdata);
	insert_link(l, 2, indata);
	list_link(l, outdata);
	remove_link(l, 2);
	list_link(l, outdata);
	remove_link(l, 1);
	list_link(l, outdata);
	remove_link(l, 0);
	list_link(l, outdata);

	return 0;
}
