#include <stdio.h>

#include "list.h"

static int intCmp(const void *data, const void *key)
{
	const int *d = data;
	const int *k = key;
	return *d - *k;
}


static void showInt(const void *data)
{
	const int *d = data;

	printf("%d   ", *d);
}

int main(void)
{
	int arr[] = {3,1,6,7,8,9,4};
	listhead_t *head;

	listheadInit(sizeof(int), &head);

	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
		listInsert(head, arr+i, HEADINSERT);  //头插入
	}

	listTraval(head, showInt);  //遍历
	printf("\n");
	printf("删除%d \n", *(arr+6));
	listDelete(head,arr+6,intCmp);  //删除
	listTraval(head, showInt);  //遍历

	printf("\n");
	int a = 20;
	printf("将  %d  修改为  %d  \n", *(arr+2),a);
	listUpdate(head , arr+2 , intCmp , &a);

	listTraval(head, showInt);  //遍历
	printf("\n");

	listDestroy(head);

	return 0;
}






















