/*
   定义一个动物结构体：
   颜色  
   名字
   月龄

   定义一个接口函数，求出整个结构中年龄最大的动物
   */



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define   NAMESIZE   32
#define   COLOR      32

struct  stu_st{
		char color[COLOR];
		char name[NAMESIZE];
		int age;
};

int zuida(struct stu_st *p);

int main(void)
{

	struct stu_st arr[3] = {};
	struct stu_st *p;
	p = arr;
	
	printf("请输入动物的颜色，名字，年龄\n");
	for(int i = 0 ; i < 3 ;i++)
		scanf("%s%s%d", arr[i].color,arr[i].name,&arr[i].age);

	for(int j = 0 ; j < 3 ; j++)
		printf("%s    %s    %d\n", arr[j].color,arr[j].name,arr[j].age);
			
	int n = zuida(arr);

	printf("年龄最大的是：\n");
	printf("%s   %s  %d\n", (p+n)->color,(p+n)->name,(p+n)->age);


	return 0;
}

int zuida(struct stu_st *p)
{
	int k = 0;
	for(int i = 0;i < 2 ; i++)
	{
		if(p->age  >  (p+1)->age)
				k = i;
		else
				k = i+1;

	}
	return k;

}






















