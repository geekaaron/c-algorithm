
#include <stdio.h>
#include <stdlib.h>

typedef struct _lnode
{
	void *pointer;
	struct _lnode *next;
} lnode, *link;

int create_link(link *l);
void destroy_link(link l);
int getlen_link(link l);
int locate_link(link l, lnode *b);
void list_link(link l, void (*outdata)(const void *pointer));
int insert_link(link l, int index, int (*indata)(void **pointer));
int remove_link(link l, int index);
