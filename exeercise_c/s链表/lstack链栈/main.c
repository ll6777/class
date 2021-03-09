#include <stdio.h>

#include "lstack.h"

int main(void)
{
	lstack_t *me;
	int n;

	lstackInit(sizeof(int), &me);   //初始化

	for (int i = 1; i < 10; i++) {
		lstackPush(me, &i);         //入栈
	}

	while (!lstackIsEmpty(me)) {
		lstackPop(me, &n);   //出栈
		printf("%d\n", n);
	}

	lstackDestroy(me);   //销毁

	return 0;
}























