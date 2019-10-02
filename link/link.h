
#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _lnode
{
	void *data;
	struct _lnode *next;
} lnode, *link;

int create_link(link *l);
void destroy_link(link l);
int getlen_link(link l);
int locate_link(link l, lnode *b);
void list_link(link l, void (*outdata)(const void *data));
int insert_link(link l, int index, int (*indata)(void **data));
int remove_link(link l, int index, lnode *b);

#endif // LINK_H
