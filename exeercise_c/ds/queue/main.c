#include <stdio.h>

#include "queue.h"

int main(void)
{
	queue_t *me;
	int n;

	queueInit(sizeof(int), 5, &me);  //队列初始化

	for (int i = 1; i < 10; i++) {
		enq(me, &i);   //入队
	}

	while (!queueEmpty(me)) {  //判断队列是否为空
		deq(me, &n);  //出队
		printf("%d\n", n);
	}

	queueDestroy(me);  //销毁

	return 0;
}
