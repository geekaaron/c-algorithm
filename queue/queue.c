
#include "queue.h"

int create_queue(queue *q)
{
	qnode *head = (qnode *)malloc(sizeof(qnode));
	if (head == NULL)
	{
		perror("malloc");
		return -1;
	}

	head->next = NULL;
	q->front = q->rear = head;
	return 0;
}

int isempty_queue(queue *q)
{
	return q->front->next? 0: 1;
}

void list_queue(queue *q, void (*outdata)(const void *data))
{
	for (qnode *p = q->front->next; p != NULL; p = p->next)
		outdata(p->data);
	printf("\n");
}

int insert_queue(queue *q, int (*indata)(void **data))
{
	void *data = NULL;
	if (indata(&data) == -1) return -1;

	qnode *b = (qnode *)malloc(sizeof(qnode));
	if (b == NULL) return -1;
	b->data = data;

	qnode *p = q->rear;
	p->next = b;
	q->rear = b;
	return 0;
}

int remove_queue(queue *q, qnode *b)
{
	if (isempty_queue(q)) return -1;

	qnode *p = q->front->next;
	q->front->next = p->next;

	if (b == NULL)
	{
		free(p->data);
		free(p);
	}
	else b = p;

	return 0;
}
