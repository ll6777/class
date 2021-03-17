#ifndef __QUEUE_H
#define __QUEUE_H

enum {LASTDEQ, LASTENQ};

typedef struct {
	void *base;
	int front; //队列头元素的下标
	int tail;// 队尾元素的下标
	int size;   //字节个数
	int capacity;	//容量
	int flag;   
}queue_t;

int queueInit(int size, int capcity, queue_t **q);  //初始化

int queueEmpty(const queue_t *q);   //空

int queueFull(const queue_t *q);  //满

int enq(queue_t *q, const void *data);   //入队

int deq(queue_t *q, void *data);  //出队

void queueDestroy(queue_t *);  //销毁

#endif
