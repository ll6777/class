/*  //求前n项和
#include<stdio.h>

int main()
{
	int i,n,sum = 0;
	
	printf("请输入n：");
	
	scanf("%d", &n);
	

	for(i = 0 ; i <= n ; i++)
	{
		sum = sum + i;
	
	}
		printf("前n项和为：%d", sum);
	
		printf("\n");
	
	return 0;

}
*/


/*
#include<stdio.h>

int main(void)
{
	int i, n = 0;
	for(i = 1 ; i < 100 ; i++)
	{
		if(i%3 == 0 && i%5 == 0)
		{
			printf("%d\n", i);
			n++;

		}
	}
	printf("100以内符合同时被3和5整除的数有%d个\n", n);

	return 0;
}
*/
/*
#include<stdio.h>

int main()
{
	int i,n;

	
	printf("请输入一个整形数:");
	
	scanf("%d", &n);
	
		for(i = 0 ; n!=0  ; i++)
		{
			printf("%d\n", n%10);
			n = n/10;
			
		}	
	
	
	return 0;
}
*/
/*
#include<stdio.h>

int main()
{
	int i,n,m;

	int fan = 0;
	printf("请输入一个整形数:");
	
	scanf("%d", &n);
	
	 	for( ; n > 0 ; )
		{
			m = n%10;
			fan = fan*10 + m;
			printf("%d, ", m);
			n = n/10;
			
		}	
	
		printf("\n");
		printf("%d\n", fan);
	
	return 0;
}*/

/*
#include<stdio.h>

int main(void)
{
	int i,n = 0;
	for(i = 100 ; i <= 999 ; i++)
	{
		if( i%10 ==6 && i%3 == 0 && i%5 != 0 )
		{
			n++;
			printf("%d ", i);
		}
	}
		printf("\n");
		printf("这样的数有%d个\n", n);
	return 0;
}
*/

/*
#include<stdio.h>

int main ()
{
	int i,n,y,r,sum = 0,l;
	printf("请正确输入年月日：");
	scanf("%d%d%d", &n,&y,&r);
	switch(y)  //计算每月之前有多少天
	{
		case 1:sum = 0; break;	
		case 2:sum = 31; break;
		case 3:sum = 59; break;
		case 4:sum = 90; break;
		case 5:sum = 120; break;
		case 6:sum = 151; break;
		case 7:sum = 181; break;
		case 8:sum = 212; break;
		case 9:sum = 243; break;
		case 10:sum = 273; break;
		case 11:sum = 304; break;
		case 12:sum = 334; break;
		default: printf("错误\n");break;
	}
	sum = sum +r;

	if(n%4 == 0 && n%100 != 0 || n%400 == 0)
	{
		l = 1;		

	}
	else l = 0;

	if(l == 1 && y > 2)
	{
		sum++;
	}
	printf("这是第%d天\n", sum);
	return 0;
}
*/
/*
#include<stdio.h>

int main()
{
	int n,y,r,sum,l;

	printf("请正确输入年月日，以空格隔开:");

	scanf("%d%d%d", &n,&y,&r);
	
	if(y > 12 || y < 1 || r > 31 || r < 1)
	{
		printf("输入的月份或日有错误");
	}
	switch(y)  //计算每月之前有多少天
	{
		case 1:sum = 0; break;	
		case 2:sum = 31; break;
		case 3:sum = 59; break;
		case 4:sum = 90; break;
		case 5:sum = 120; break;
		case 6:sum = 151; break;
		case 7:sum = 181; break;
		case 8:sum = 212; break;
		case 9:sum = 243; break;
		case 10:sum = 273; break;
		case 11:sum = 304; break;
		case 12:sum = 334; break;
		default: printf("错误\n");break;
	}

	sum = sum +r;

	if(n%4 == 0 && n%100 != 0 || n%400 == 0)
	{
		l = 1;		

	}
	else l = 0;

	if(l == 1 && y > 2)
	{
		sum++;
	}
	printf("这是第%d天\n", sum);
	return 0;
}
*/
	
/*
//判断输入的数字是不是质数
#include<stdio.h>

int main()
{
	int num,i,a = 0;

	printf("请输入一个整数：\n");

	scanf("%d", &num);

	for(i = 2 ; i < num ; i++)
	{
		if(num % i == 0)
		{
			a++;
		}

	}
	if(a == 0)
		printf("%d这是一个质数\n",num);
	else	
		printf("%d这不是一个质数\n",num);

	return 0;
}
*/

/*
//统计100--300之间的质数
#include<stdio.h>

int main()
{
	int num,i,a = 0,sum = 0;
	for(num = 100 ; num < 300 ; num ++)
	{
		a = 0;
		for(i = 2 ; i < num ; i++)
		{	
			if(num % i == 0)
			{	
				a++;
			}

		}
			if(a == 0)
			{
				printf("%d这是一个质数\n",num);
				sum++;
			}		
	}
	printf("一共有%d个质数\n", sum);

	return 0;
}
*/

/*
//输入一个五位数   将偶数位重组
#include<stdio.h>

int main(void)
{
	int num,i = 10000,tmp,res = 0;

	printf("请输入一个5位数：\n");
	scanf("%d", &num);

	if(num < 10000 || num > 99999)
		printf("错误");
	else
	{
		while(i >0)
		{
			tmp = num / i;
			if(tmp % 10 % 2 == 0 )
				res = res * 10 + tmp % 10;
			i /= 10;

		}
		
	}
	printf("重组的数为：%d\n", res);

	return 0;
}
*/

 //9*9  乘法表
#include<stdio.h>

int main(void)
{
	int h,l,i;
	for(h = 1 ; h<=9 ; h++)
	{
		for(l = 1 ; l <= h ; l++)
		{
			printf("%d*%d = %2d ",l,h,h*l);


		}
	printf("\n");

	}
	return 0;
}






















