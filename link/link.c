
#include "link.h"

int create_link(link *l)
{
	*l = (link)malloc(sizeof(lnode));
	if (*l == NULL) return -1;				// -->
	(*l)->pointer = (*l)->next = NULL;
	return 0;
}

void destroy_link(link l)
{
	lnode *p = l;

	for (lnode *p = l; p != NULL; p = p->next)
		free(p);
	l = NULL;
}

int getlen_link(link l)
{
	int len = 0;
	lnode *p = l->next;
	while (p != NULL && ++len) p = p->next;
	return len;
}

void list_link(link l, void (*outdata)(const void *pointer))
{
	for (lnode *p = l->next; p != NULL; p = p->next)
		outdata(p->pointer);
	printf("\n");
}

int locate_link(link l, lnode *b)
{
	lnode *p = l->next;
	for (int i = 0; p != NULL; p = p->next, i++)
		if (p == b) return i;				// -->
	return -1;
}

int insert_link(link l, int index, int (*indata)(void **pointer))
{
	if (index < 0 || index > getlen_link(l)) return -1;	// -->

	void *pointer = NULL;
	if (indata(&pointer) == -1) return -1;			// -->

	lnode *b = (lnode *)malloc(sizeof(lnode));
	if (b == NULL) return -1;				// -->
	b->pointer = pointer;

	lnode *q = l;
	lnode *p = l->next;
	while (index--)
	{
		q = p;
		p = p->next;
	}
	q->next = b;
	b->next = p;

	return 0;
}

int remove_link(link l, int index)
{
	if (index < 0 || index > getlen_link(l)) return -1;	// -->

	lnode *q = l;
	lnode *p = l->next;
    	while (index--)
	{
		q = p;
		p = p->next;
	}
	q->next = p->next;
	free (p->pointer);
	free(p);

	return 0;
}
