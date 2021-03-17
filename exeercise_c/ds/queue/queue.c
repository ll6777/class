#include <stdlib.h>
#include <string.h>

#include "queue.h"

int queueInit(int size, int capcity, queue_t **q)  //初始化
{
	*q = malloc(sizeof(queue_t));
	if (NULL == *q)
		return -1;
	(*q)->base = calloc(capcity, size);
	if (NULL == (*q)->base) {
		free(*q);
		return -1;
	}
	(*q)->front = (*q)->tail = 0;
	(*q)->capacity = capcity;
	(*q)->size = size;
	(*q)->flag = LASTDEQ;

	return 0;
}

int queueEmpty(const queue_t *q)  //空
{
	return q->front == q->tail && q->flag == LASTDEQ;
}

int queueFull(const queue_t *q)  //满
{
	return q->front == q->tail && q->flag == LASTENQ;
}

int enq(queue_t *q, const void *data)  //入队
{
	if (queueFull(q))
		return -1;
	memcpy((char *)q->base + q->tail * q->size, data, q->size);
	q->tail = (q->tail + 1) % q->capacity;

	q->flag = LASTENQ;

	return 0;
}

int deq(queue_t *q, void *data)  //出队
{
	if (queueEmpty(q))
		return -1;
	memcpy(data, (char *)q->base + q->front * q->size, q->size);
	q->front = (q->front + 1) % q->capacity;

	q->flag = LASTDEQ;

	return 0;
} 

void queueDestroy(queue_t *q)  //销毁
{
	free(q->base);
	free(q);
}


