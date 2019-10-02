
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _qnode
{
	void *data;
	struct _qnode *next;
} qnode;

typedef struct
{
	struct _qnode *front;
	struct _qnode *rear;
} queue;

int create_queue(queue *q);
int isempty_queue(queue *q);
void list_queue(queue *q, void (*outdata)(const void *data));
int insert_queue(queue *q, int (*indata)(void **data));
int remove_queue(queue *q, qnode *b);

#endif // QUEUE_H
