
/*   1. 如果一个正整数从左、右来读都是一样的，则称为回文整型数。
数学中有名的"回数猜想"之迷，至今未解决.
何为回数猜想？取任何一个数，再把它到过来，并把两个数相加，然后把这个和数再倒过来
与原和数相加，重复此过程，一定能获得一个回数。
例如68
倒过来86
68+86=154
154+541=605
605+506=1111(回数)
编程，输入任意整型数，按上述方法产生一个回数，为简单起见，最多计算7步，看是否能
得到一个回数。
思路:
主函数中接受键盘数据，读入整型数.
显示该数与其倒数的和，输出每一步计算步骤。
子函数1，计算一个数的倒数
子函数2，验证是否是回文数
是则主函数打印"经过n次计算，得到回数"
超过7次未得到回数，显示"经过n次计算未得到回数"    */
/*
#include<stdio.h>

int  daoshu(int j,int k );
int  yanzheng(int a,int k);

int main(void)
{
	int n,i,j = 0,k = 0;
	printf("请输入一个整形数： \n");
	scanf("%d", &n);
	
	for(i = 0 ; i < 7 ; i++)
	{
		k = 0;
		j = n;
		k = daoshu(j,k);
		if(yanzheng(n,k)){
			printf("%d 这是一个回数\n", n);	return 0;}
		else
			n = n + k;
	}
	printf("经过n次计算未得到回数\n");
	
	return 0;
}
int  yanzheng(int a,int k)
{
	if(a == k)
		return 1;
	else
		return 0;
}

int  daoshu(int j,int k )
{
	while(j)
	{
		k = k*10 + j%10;
		j = j/10;
	}
	return k;
}
*/

//
/*
#include<stdio.h>
int rec(int n);
int main()
{
		int i,j,n,f=1;
		scanf("%d",&n);
		while(f)
		{
				if(rec(n)==n)
						f=0;
				else
						n+=rec(n);
		}
		printf("%d",n);
}
int rec(int n)
{
		int s=0;
		while(n)
		{
				s*=10;
				s+=n%10;
				n/=10;
		}
		return s;
}
*/



//2. 定义一个函数，根据给定的年月日，返回这是这一年的第几天

/*
#include<stdio.h>

int cha(int y,int i,int d);
int main(void)
{
	int year,month,day;
	int sum = 0;
	
	printf("请输入年月日：");
	scanf("%d%d%d", &year,&month,&day);
	sum = cha(year,month,day);

	printf("这是%d年第%d天 \n", year,sum);
	return 0;
}
int cha(int y,int i,int d)
{
	int sum = 0;
	
	for(int m = 1 ; m < i ; m++)
	{
	
	if(m == 2)	
	{
		if(y%4 == 0 && y%100 != 0 || y%400 == 0)
				sum = sum + 29;
		else sum = sum + 28;
	}
	else if(m==1  || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
	{
				sum = sum + 31;	
	}
	else if(m==4 || m==6 || m==9 || m==11)
	{
		sum = sum + 30;
	}
	}
	sum = sum +d;
	return sum;
}
*/




//3. 判断给定的整型数是否是素数
/*
#include<stdio.h>

int sushu(int k);
int main(void)
{
	int n;
	printf("请输入一个整数：\n");
	scanf("%d", &n);
	if(sushu(n))
			printf("%d  这是一个素数\n",n);
	else
			printf("%d  这不是一个素数\n", n);

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








//4. 定义一个函数，求得斐波那契数列第n项
/*
#include<stdio.h>
#include<stdlib.h>


int fib(int n)
{
	if(n < 0)
	{
	return -1;     //出错条件
	printf("输入错误");
	}
	if(n == 1 || n == 2)
	{
	return 1;      //已知条件
	}
	{
	return fib(n - 1) + fib(n - 2 );  //常规条件
	}
}

int main()
{
 int num;

 printf("请输入要求的fib数列第n项：");
 scanf("%d",&num);
 
	printf("第n项为：");
 printf("%d\n",fib(num));

 exit(0);

}
*/




//5. 求得两个整型数的最大公约数

#include<stdio.h>

int yueshu(int a,int b);

int main(void)
{
	int a,b,c;
	printf("请输入两个整形数：\n");
	scanf("%d%d", &a,&b);

		c = yueshu(a,b);
		printf("最大公约数为：%d  \n",c );
	
	return 0;
}

int yueshu(int a,int b)
{
	for(int i = a ; i > 0 ; i--)
	{
		if(a % i == 0 && b % i == 0 )
				return i;
	}
	
}
















