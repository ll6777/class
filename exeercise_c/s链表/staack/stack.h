#ifndef __STACK_H
#define __STACK_H

typedef struct {
	void *base;  //栈底
	void *top;  //栈顶
	int size;   //成员字节个数
	int capacity;   //容量
}stack_t;

int stackInit(int size, int capacity, stack_t **s);

int stackIsEmpty(const stack_t *s);

int stackIsFull(const stack_t *s);

int stackPush(stack_t *s, const void *data);

int stackPop(stack_t *s, void *data);

void stackDestroy(stack_t *s);

#endif





















