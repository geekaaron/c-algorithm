
#include "link.h"

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
	link l;

	create_link(&l);
	insert_link(l, 0, indata);
	list_link(l, outdata);
	insert_link(l, 1, indata);
	list_link(l, outdata);
	insert_link(l, 2, indata);
	list_link(l, outdata);
	remove_link(l, 2, NULL);
	list_link(l, outdata);
	remove_link(l, 1, NULL);
	list_link(l, outdata);
	remove_link(l, 0, NULL);
	list_link(l, outdata);

	return 0;
}
