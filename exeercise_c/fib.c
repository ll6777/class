/*    
1. 求非波数列
2. 求三个数中的最大值

1 1 2 3 5 8 13 

 */ 

#include<stdio.h>

int  fibnum(int n);

int minnum(int a,int b,int c);

int main(void)
{
	int n,sum = 0 ;
	printf("请输入要求的第n项：");
	scanf("%d", &n);
	printf("第%d项为：", n);

	printf(" %d\n", fibnum(n));
	printf("%d\n",minnum(11,22,43));
}

int  fibnum(int n)
{
	if(n < 0)
	{
		printf("输入错误！！！");
		return -1;
	}
	if(n == 1 || n == 2)
		return 1;
	else
		return fibnum(n -1) + fibnum(n - 2);

}
int minnum(int a,int b,int c)
{
		int min;
		min = a > b ? b : a;
		min = min > c ? c:min;
		return min;
}

































