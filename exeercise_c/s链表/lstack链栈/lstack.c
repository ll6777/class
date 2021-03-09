#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lstack.h"

int lstackPush(lstack_t *ls,const void *data)
{
	return listInsert(ls, data, INSERTHEAD);
}

static int alwaysCmp(const void *data, const void *key)
{
	return 0;
}

int lstackPop(lstack_t *ls, void *data)     //出栈
{
	return listFetch(ls, NULL, alwaysCmp, data);

}

void lstackDestroy(lstack_t  *ls)  //销毁
{
	listDestroy(ls);

}




















