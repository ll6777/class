

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>



int main(void)
{
	int a[5];   //定义
	int i;
	int a1[5] = {1,3,5,7,9};//初始化

//	srand(time(NULL));//按时间出随机值   1秒内同时运行一样  1秒后不一样
	srand(getpid());  //按照运行进程号出随机值   每一次都不一样

	for(i = 0 ; i < 5 ; i++)   //赋值
	{
		a[i] = rand() % 100 ;
	}

	for(i = 0 ; i < 5 ; i++)  //遍历
		printf("%2d : %p      \n",a[i], &a[i]);
	printf("\n");

	
	printf("%d  \n", *( a1+1));
	printf("%ld  \n", sizeof a1);
	return 0;
}


/*
//包含10个元素的数组    输出交换最大数和最小数后的数组

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int a[10];
	int	i,max = 0,min = 0;

	srand(getpid());//按照进程号获取随机数
	for(i = 0 ; i < 10 ; i++) //赋值
	{
		a[i] = rand() % 100;
	}

	for(i = 0 ; i < 10 ; i++)//遍历
	{
		printf("%d  ", a[i]);
	
	}
	printf("\n");
	for(i = 0 ; i < 10 ; i++)//找最大数和最小数
	{
		if(a[i] > a[max])
		{
			max = i; //保存最大值的坐标
		}
		 
		if(a[i] <a[min])
		{
			min = i;//保存最小值的坐标
		}

	}
	i = a[max];//交换最大值最小值
	a[max] = a[min];
	a[min] = i; 
	
	printf("\n");

	for(i = 0 ; i < 10 ; i++)//打印交换后的数组
	{
		printf("%d  ", a[i]);
	
	}

	printf("\n");


	return 0;
}

*/











