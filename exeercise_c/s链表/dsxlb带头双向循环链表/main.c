#include<stdio.h>
#include<stdlib.h>
#include "ds.h"

static void showInt(const void *data)  //打印函数
{
	const int *d = data;

	printf("%d   ", *d);
}

static int cmpInt(const void *data, const void *key) //比较函数
{
	const int *d = data;
	const int *k = key;
	return *d - *k;
}
int main(void)
{
	int arr[] = {3,1,6,7,8,9,4};
	listhead_t *head;
	int k = 7;
	listheadInit(sizeof(int), &head);   // 初始化
	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
		listInsert(head, arr+i, HEADINSERT);   // 头插法
	}
	listTraval(head,showInt);  //遍历
	printf("\n");
	printf("把%d删除了 \n", k);
	listDelete(head , &k,  cmpInt);    //删除
	listTraval(head,showInt);  //遍历
	printf("\n");

	k = 8;     	int *t;
	t = listFetch(head , &k , cmpInt);
	printf("把%d拿了出来 \n", *t);
	listTraval(head,showInt);  //遍历
	printf("\n");

	int a;
	a = listIsEmpty(head);   //判断是否为空 
	printf("%d \n", a);
	listDestroy(head);  //销毁

	return 0;
}





