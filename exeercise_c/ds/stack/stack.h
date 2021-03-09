#ifndef __STACK_H
#define __STACK_H

typedef struct {
	void *base;  //栈底
	void *top;   //栈顶
	int size;    //成员字节个数
	int capacity;   //容量
}stack_t;

int stackInit(int size, int capacity, stack_t **s);  //栈初始化  字节个数  容量  栈

int stackIsEmpty(const stack_t *s);   //判断栈 是否为空

int stackIsFull(const stack_t *s);   //判断栈是否为满

int stackPush(stack_t *s, const void *data);  //入栈

int stackPop(stack_t *s, void *data);   //出栈

void stackDestroy(stack_t *s);   //销毁

#endif

