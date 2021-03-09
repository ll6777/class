#include <stdio.h>

#include "stack.h"

int main(void)
{
	stack_t *mystack;
	int p;

	stackInit(sizeof(int), 10, &mystack);  //初始化

	for (int i = 1; i < 100; i++) {
		if (stackPush(mystack, &i) != 0)   //入栈
			break;
	}

	while (!stackIsEmpty(mystack)) {   //判断是否为空
		stackPop(mystack, &p);   //出栈
		printf("%d\n", p);
	}

	stackDestroy(mystack);  //销毁

	return 0;
}

