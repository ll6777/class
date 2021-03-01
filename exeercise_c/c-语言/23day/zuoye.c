
/*
//1. 题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int i,j,k,sum = 0;
	for(i = 1; i < 5 ; i++)	
		for(j = 1; j < 5 ; j++)
			for(k = 1; k < 5 ; k++)
				if(i!=j && i!=k && j!=k)
				{
					printf("%d    ", i*100+j*10+k);
					sum++;
				}
	
	printf("一共有%d个这样的三位数\n", sum);

	return 0;
}
*/


/*
//2. 题目：有一个已经排好序的数组。现输入一个数，要求按原来的规律将它插入数组中

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a[8] = {1,2,3,4,5,9,10};
	int i,j,t,m;
	printf("原数组为： \n");
	for(i = 0 ; a[i] ; i++)
	{
		printf(" %d ", a[i]);
	}
	printf("\n");
	printf("请输入要插入的数：\n");
	scanf("%d", &m);
	a[7] = m;
	for(i = 0 ; i < 7 ; i++)
	{
		for(j=0;j<7-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	printf("\n");
	printf("插入后的数组为：\n");
	for(i = 0 ; i < 8 ; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
*/

/*
//3. 题目：海滩上有一堆桃子，五只猴子来分。第一只猴子把这堆桃子平均分为五份，多了一个，这只 猴子把多的一个扔入海中，拿走了一份。第二只猴子把剩下的桃子又平均分成五份，又多了 一个，它同样把多的一个扔入海中，拿走了一份，第三、第四、第五只猴子都是这样做的， 问海滩上原来最少有多少个桃子？

#include<stdio.h>

int main(void)
{
	int i,sum = 5;
	for(i= 5 ; i >=1 ; i--)
	{
		printf("第%d只分完之后有%d个\n", i,sum);
		if(i == 1){
			break;}
		sum = (sum+1)*5;
	}
	sum++;
	printf("一共有%d个桃子\n", sum);

	return 0;
}
*/


/*
//4. 定义一个接口函数，功能是返回一个能容纳10个整型元素的数组，再定义一个能向数组里插入新元素和一个能遍历数组的函数
#include<stdio.h>
#include<stdlib.h>
#define   N   10

int *jiekou();
int *charu(int a,int *p);
void show(int *p);
int main(void)
{
	int *p;:int a;
	p = jiekou();
	scanf("%d", &a);
	p = charu(a,p);
	show(p);

	return 0;
}
int *jiekou()
{
	static int a[N] = {0};
	return a;
}
int *charu(int a,int *p)
{
	for(int i = 0; i<N  ; i++)
	{
		p[i] = a;
		break;
	}
	return p;
}
void show(int *p)
{
	for(int i=0;i<N;i++)
		printf("%d  ", p[i]);
	printf("\n");

}
*/

//5. 定义一个接口函数，使得能从标准输入读入一行字符串并通过函数的参数返回此字符串，同时要满足空间大小满足字符串长度





#include<stdio.h>

int main(int agrc, char*agrv[])
{
	int i, m, j, k, count;
	for (i = 4; i<10000; i += 4)
/*i为5个猴子分配桃子后最后剩余的桃子，必须为4的倍数,然后以此为基础，
向上推5次，如果刚好能够推到第五次，则此剩余的桃子数i是满足条件的,/
	{
		count = 0;
		m = i;
		for (k = 0; k<5; k++)
		{
			j = i / 4 * 5 + 1;
			i = j;	
			if (j % 4 == 0)
				count++;
			else
				break;
		}
		i = m;
		if (count == 4)
		{
			printf("原来最少的桃子数为：%d\n", j);
			break;
		}
	}
		
		return 0;
}







