#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist.h"

static void showInt(const void *data)
{
	const int *d = data;
	printf("%d  ", *d);

}
static int intcmp(const void *data, const void *key)
{	
	const int *d = data;
	const int *k = key;
	return *d - *k;
}


int main(void)
{
	seqlist_t  *mylist;
	int key;
	void *f;
	int t;
	mylist = seqlistInit(sizeof(int));

	for(int i = 1; i <= 20 ; i += 2)
	{
		seqlistInesert(mylist, &i);   //增加新元素

	}
	printf("原顺序表为：\n");
	seqlisTraval(mylist, showInt);   //遍历
	printf("\n");

	key = 5;
//	f = seqlistFind(mylist, &key, intcmp);   //查找
//	if(f == NULL)
//		printf("没有值为%d的元素\n" , key);
//	else
//		printf("找到了%d\n", *(int *)f);


	seqlistDelete(mylist, &key , intcmp);   //删除


	printf("删除%d 后的顺序表为：\n",key);
	seqlisTraval(mylist, showInt);   //遍历
	printf("\n");
	key = 7;
	t = 22;
	seqlistUpdate(mylist, &key, intcmp, &t);   //修改

	printf("把%d 修改为%d 后的顺序表为：\n",key,t);
	seqlisTraval(mylist, showInt);   //遍历
	printf("\n");


	seqlistDestroy(mylist);  //销毁

	seqlisTraval(mylist, showInt);   //遍历
	return 0;
}














