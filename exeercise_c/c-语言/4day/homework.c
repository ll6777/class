
//day04
//1. 随机产生一个由10个整型元素组成的数组，将数组元素从小到大排序

/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int a[10];
	int	i,j,t;

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
	for(i = 0 ; i < 9 ; i++)//从小到大排列   冒泡排序循环n-1 趟 排序 
	{
		for(j=0;j< 9-i;j++)     //每次比较n-i-1 次   
		{
				if(a[j]>a[j+1])
				{
						t=a[j];
						a[j]=a[j+1];
						a[j+1]=t;
				}
		}
	}
	printf("\n");
	for(i = 0 ; i < 10 ; i++)//打印交换后的数组
	{
		printf("%d  ", a[i]);
	}
	printf("\n");

	return 0;
}
*/









/*
2. 定义一个能存储10个学生成绩的数组，打印成绩分布图
100: *
90~99: 
80~89: **
70~79:
60~69:
....
0~9:
*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int a[10];
	int i,sum = 0;
	srand(getpid());
	for(i = 0 ; i < 10 ; i++) {  //给数组每一个元素赋随机值
		a[i] = rand() % 100 ;
		printf("%d  ", a[i]);
	}
		printf("\n");
		printf("100 :");
		for(i = 0 ; i < 10 ; i++)
		{
			if(a[i] == 100 ){
			sum++;
			printf("*");
			}
		}
			printf("        一共%d个\n", sum);
		

		printf("90--99 :");
			sum = 0;
		for(i = 0 ; i < 10 ; i++)
		{
			if(a[i] >= 90  && a[i] < 100 ){
			sum++;
			printf("*");
			}
		}
			printf("        一共%d个\n", sum);


		printf("80--89 :");
			sum = 0;
		for(i = 0 ; i < 10 ; i++)
		{
			if(a[i] >= 80  && a[i] < 90 ){
			sum++;
			printf("*");
			}
		}
			printf("        一共%d个\n", sum);


		printf("70--79 :");
			sum = 0;
		for(i = 0 ; i < 10 ; i++)
		{
			if(a[i] >= 70  && a[i] < 80 ){
			sum++;
			printf("*");
			}
		}
			printf("        一共%d个\n", sum);



		printf("60--69 :");
			sum = 0;
		for(i = 0 ; i < 10 ; i++)
		{
			if(a[i] >= 60  && a[i] < 70 ){
			sum++;
			printf("*");
			}
		}
			printf("        一共%d个\n", sum);


		printf("50--59 :");
			sum = 0;
		for(i = 0 ; i < 10 ; i++)
		{
			if(a[i] >= 50  && a[i] < 60 ){
			sum++;
			printf("*");
			}
		}
			printf("        一共%d个\n", sum);


		printf("40--49 :");
			sum = 0;
		for(i = 0 ; i < 10 ; i++)
		{
			if(a[i] >= 40  && a[i] < 50 ){
			sum++;
			printf("*");
			}
		}
			printf("        一共%d个\n", sum);


		printf("30--39 :");
			sum = 0;
		for(i = 0 ; i < 10 ; i++)
		{
			if(a[i] >= 30  && a[i] < 40 ){
			sum++;
			printf("*");
			}
		}
			printf("        一共%d个\n", sum);



		printf("20--29 :");
			sum = 0;
		for(i = 0 ; i < 10 ; i++)
		{
			if(a[i] >= 20  && a[i] < 30 ){
			sum++;
			printf("*");
			}
		}
			printf("        一共%d个\n", sum);


		printf("10--19 :");
			sum = 0;
		for(i = 0 ; i < 10 ; i++)
		{
			if(a[i] >= 10  && a[i] < 20 ){
			sum++;
			printf("*");
			}
		}
			printf("        一共%d个\n", sum);


		printf("0--9 :");
			sum = 0;
		for(i = 0 ; i < 10 ; i++)
		{
			if(a[i] >= 0  && a[i] < 10 ){
			sum++;
			printf("*");
			}
		}
			printf("        一共%d个\n", sum);


	return 0;
}

*/







//3. 模拟游戏：41个人编好号(1~41)围成一圈，从1号开始数数，数到3则退出游戏，下一个人再从1开始数....最后留下的那个人是几号

/*
#include<stdio.h>
#include<stdlib.h>

#define   NUM   41

int main(void)
{

	int i, a[NUM];
	int people = NUM,n = 0;
	for(i = 0 ; i < NUM ; i++ )//循环给数组赋值  并打印
	{
		a[i] = i+1;
		printf("%2d ", a[i]);
	}
	printf("\n");
	i = 0;
	while(people > 1)
	{
		if(a[i] != 0 )
			n++;
		if(n == 3 )
		{
			printf("第%d个人退出游戏 \n", a[i]);
			a[i] = 0;
			people--;
			n = 0;
		}
		i++;
		if(i == (NUM ))
			i = 0;
	}
	for(i = 0 ; i < NUM ; i++ )//循环给数组赋值  并打印
	{	
		printf("%2d ", a[i]);
		if(a[i] != 0)
		printf("最后%d赢得了游戏\n",a[i]);
	}
	return 0;
}
*/

//选择排序从小到大排列 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int a[10];
	int	i,j,t;

	srand(getpid());//按照进程号获取随机数
	for(i = 0 ; i < 10 ; i++) //赋值
	{
		a[i] = rand() % 100;
		printf("%d  ", a[i]);	
	}
	printf("\n");
	for(i = 0 ; i < 9 ; i++)//从小到大排列   选择排序循环n 趟 排序 
	{
		for(j= i+1;j< 10;j++)     //每次拿着a[i] 和  a[j]  比较
		{
				if(a[i]>a[j])  //交换 
				{
						t=a[i];
						a[i]=a[j];
						a[j]=t;
				}
		}
	}
	printf("\n");
	for(i = 0 ; i < 10 ; i++)//打印交换后的数组
		printf("%d  ", a[i]);
	printf("\n");

	return 0;
}















//4. 读入10个整型变量，求得十个数中所有的素数打印输出
/*
#include<stdio.h>
#include<stdlib.h>

int sushu(int k);

int main(void)
{
	int i,a[10];
	printf("请输入10 个数：\n");
	for(i = 0 ; i < 10 ; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("这10个数中素数有：\n");
	for(i = 0 ; i < 10 ; i++)
	{
		if(sushu(a[i]))
			printf("%d  这是一个素数\n",a[i]);
	
	}

	return 0;
}

int sushu(int k)
{
	for(int i = 2 ; i < k ; i++)
	{
		if(k % i == 0)
			return 0;
		else
			return 1;
	}

}

*/




















