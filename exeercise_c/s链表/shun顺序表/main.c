#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist.h"
#define  NAMESIZE   32

struct stu_st{
	char name[NAMESIZE];
	int age;
};

static void showStu(const void *data)
{
	const struct stu_st *d = data;
	printf("%s   %d  \n", d->name, d->age);

}
static int intcmp(const void *data, const void *key)
{	
	const struct stu_st *d = data;
	const int *k = key;
	return d->age - *k;
}
static int nameCmp(const void *data, const void *key)
{
	const struct stu_st *d = data;
	const char *k = key;
	return strcmp(d->name, k);
}
int main(void) 
{
	seqlist_t  *mylist;
	int key;
	struct stu_st *f;
	struct stu_st s;
	char *delname;
//	int t;
	mylist = seqlistInit(sizeof(struct stu_st));

	for(int i = 1; i <= 20 ; i += 2)
	{
		s.age = 20+i;
		snprintf(s.name,NAMESIZE, "stu%d", i);
		seqlistInesert(mylist, &i);   //增加新元素

	}
	seqlisTraval(mylist, showStu);
	key = 25;
	f = seqlistFind(mylist,&key,intcmp);
	if(f == NULL)
		printf("没有为   %d的  ", key);
	else
		printf("找到了%s\n", f->name);

	//删除
	delname = "stu11";
	seqlistDelete(mylist, delname, nameCmp);
	seqlisTraval(mylist, showStu);

	seqlistDestroy(mylist);

/*	printf("原顺序表为：\n");
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

	seqlistDestroy(mylist);  //销毁  */

	return 0;
}














