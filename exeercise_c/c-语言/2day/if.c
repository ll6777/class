
/*比较abc三个数，从大到小排列*/
/*
#include<stdio.h>

int main(void)
{
	int a,b,c,t;
	printf("请输入三个数：");
	
	scanf("%d%d%d",&a,&b,&c);
	if(a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	if(a < c)
	{
		t = a;
		a = c;
		c = t;
	}
	if(b < c)
	{
		t = b;
		b = c;
		c = t;
	}
	
	printf("a == %d ,b == %d , c == %d \n",a,b,c);

	return 0;
}
*/

/*
//成绩划分段落

#include<stdio.h>

int main(void)
{
	int num,n,i = 0;
	while(i < 10)
	{
	printf("请输入你的成绩：\n");

	scanf("%d", &num);
	i++;
	n = num/10;
//	
	if(num >= 90  &&  num <= 100)
	{
		printf("你的成绩为 A \n");
	}

	else if(num >= 80  &&  num <= 89)
	{
		printf("你的成绩为 B \n");
	}

	else if(num >= 70  &&  num <= 79)
	{
		printf("你的成绩为 C \n");
	}

	else if(num >= 60  &&  num <= 69)
	{
		printf("你的成绩为 D \n");
	}
	else if(num >= 0  &&  num <= 59)
	{
		printf("你的成绩为 E \n");
	}
	else
			printf("输入错误！！！\n");
//
	if(num >100  ||  num <0)
	{	printf("输入错误！！！\n");
			continue;
	}
	
	switch(n)
	{
		case 10:
			printf("A\n");
			break;

		case 9:
			printf("A\n");
			break;

		case 8:
			printf("B\n");
			break;

		case 7:
			printf("C\n");
			break;

		case 6:
			printf("D\n");
			break;

		default:
			printf("E\n");
			break;
	}
	}


	return 0;
}
*/
// 循环练习题


//1.  小明10次运球   第5次的时候肚子痛  终止循环
/*
#include<stdio.h>

int main(void)
{
	int i = 0;

	while(i<10)
	{
		printf("小明第%d次运球 \n", i+1);
		i++;
			if(i==4)
			{	printf("小明肚子痛，无法继续。");
				break;
			}
	}
	return 0;
}
*/

/*
//2.    键盘输入n    求前n项和

#include<stdio.h>

int main(void)
{
	int i,n,sum = 0;

	printf("请输入n的值：\n");

	scanf("%d", &n);

	for(i = 1 ;  i <= n ; i=i+2)
	{
		sum = sum + i;
		printf("%d+", i);
	}
	printf("\b =%d  \n", sum);

	return 0;
}
*/

/*
//	求逆序数

#include<stdio.h>

int main(void)
{
	int n,i,num = 0,res = 0, sum = 0;

	printf("请输入一个数：");

	scanf("%d", &n);

	while(n > 0)
	{
	num = num*10 + n%10;
	n = n/10;
	
	}
	printf("逆序数为：%d \n", num);


	for(i = 100  ;  i < 1000 ; i++)
	{
		res = 0;
		num = i;
		while(num > 0)
		{
			res = res + (num%10)*(num%10)*(num%10);
			num = num/10;

		}
		if(i == res)
		{
			printf("水仙花数： %d   \n",  i);
			sum++;
		}
	}


	return 0;
}
*/



/*
//找100--999所有水仙花数
#include<stdio.h>

int main(void)
{	
	int i,a,b,c,sum = 0;
	for(i = 100  ;  i < 1000 ; i++)
	{
		a = i/100;
		b = i/10%10;
		c = i%10;
		if(i == a*a*a + b*b*b + c*c*c)
		{
			printf("水仙花数： %d   \n",  i);
			sum++;
		}
	}
	printf("一共有 %d 个水仙花数\n", sum);
	return 0;
}
*/

/*
//读入四则运算   计算结果   例： 读入1+2    输出  1+2 = 3

#include<stdio.h>

int main()
{
	int a,b;
	char x;
	printf("请输入：\n");

	scanf("%d%c%d", &a,&x,&b);
	
	if(x == '+')
		printf("%d+%d=%d\n", a,b,a+b);

	else if(x == '-')
		printf("%d-%d=%d\n", a,b,a-b);

	else if(x == '*')
		printf("%d*%d=%d\n", a,b,a*b);

	else if(x == '/')
		printf("%d/%d=%d\n", a,b,a/b);

	return 0;
}
*/

/*
//2   读入一个四位数   判断十位上的数字出现的个数

#include<stdio.h>

int main(void)
{
	int num,a,i,sum = 0;
	printf("请输入一个四位数：");
	scanf("%d", &num);
	a = num/100%10;
	while(num > 0)
	{	
		i = num%10;
		num = num /10;
		if(a == i)
			sum++;

	}
	printf("十位数字出现%d次。\n", sum);	

	return 0;
}
*/

/*
//3   打印菱形   如 读入4 行    输出4*4菱形

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n,i,j,a;

	printf("请输入一个几行的菱形：");
	scanf("%d", &n);
	for(i = 0 ; i < n+n-1 ; i++)
	{
		if(i < n)
		{
		for(j = 1 ; j <abs(n-i) ; j++)
			printf(" ");
		for(j = 0 ; j <= i*2; j++)
				printf("*");
		printf("\n");
		}else
		{
			for(j = 0 ; j <= abs(n-i) ; j++)
				printf(" ");
			for(j = 2*j+1 ; j < n*2 ; j++)
				printf("*");
			printf("\n");
		}

	}

	return 0;
}
*/
//菱形
/*
#include<stdio.h>

int main(void)
{
	int row;
	printf("请输入一个几行的菱形：");
	scanf("%d", &row);
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < row-i-1 ; j++ )
				printf("  ");
		for(int j = 0 ; j< 2*i+1 ; j++)
				printf("* ");
		printf("\n");
	}

	for(int l = row-2; l >= 0 ; l--)
	{
		for(int j = 0 ; j < row-l-1 ; j++)
				printf("  ");
		for(int j = 0 ; j < 2*l+1 ; j++)
				printf("* ");
		printf("\n");
	}


	return 0;
}
*/



/*
//一个2000以内的整数   它 +100后是完全平方数   再加168还是完全平方数   求这个数
#include<stdio.h>

int main(void)
{
	int i,j,k;

	for(i = 0 ; i < 2000  ;  i++)
	{
		for(j = 0 ; j < 45 ; j++)
				if((i+100) == j*j   )
				{
						for(k = 0 ; k < 48  ;   k++)
							if((i+268) == k*k  )
									printf("%d i+100: %d   i+268: %d\n", i,i+100,i+268);
				}
	}



	return 0;
}
*/
/*
//调用函数求2000以内完全平方数
#include<stdio.h>

int wqpfs(int  i );
int main(void)
{
	int i,res,res1;
	for(i = 0 ; i < 2000 ; i++)	
	{
		wqpfs(i);


	}
		
	return 0;
}


int wqpfs(int  i )
{
		
		for(int j = 0 ; j < 45 ; j++)
				if((i+100) == j*j   )
				{
						for(int k = 0 ; k < 48  ;   k++)
								if((i+268) == k*k  )
										printf("%d i+100: %d   i+268: %d\n", i,i+100,i+268);
				}
}
*/

/*
//判断所给数是否是完全平方数
#include<stdio.h>

int wqpfs(int  i );
int main(void)
{
	int i;
	scanf("%d", &i);
	if(wqpfs(i))
		printf("%d是一个完全平方数 \n", i);
	else
		printf("%d不是一个完全平方数 \n", i);

	return 0;
}


int wqpfs(int  i )
{
		
	for(int j = 0 ; j < 45 ; j++)
	{
		if(i == j*j)
			return 1;
	} 
	return 0;			
}
*/





/*
//键盘输入年月   求这一年的这一月有几天
#include<stdio.h>

int main(void)
{
	int y,m,a = 0,sum = 0;
	printf("请输入年月：\n");
	scanf("%d%d",&y,&m);
	if(y%4 == 0 &&  y%100  !=  0  || y%400  == 0)	
		a = 1;
	else a = 0;


	if(m == 2)	
		printf("%d年%d月有%d 天\n",y,m,28+a);
	else if(m==1  || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
	{
		sum =31;
		printf("%d年%d月有%d 天\n",y,m,sum);
	}
	else if(m==4 || m==6 || m==9 || m==11)
	{
		sum = 30;
		printf("%d年%d月有%d 天\n",y,m,sum);
	}


	return 0;
}
*/

/*
//判断所给月份是多少天
#include<stdio.h>


int isLeap(int y);
int dayOfMonth(int m ,int y );

int main(void)
{
	int month, year;	

	scanf("%d%d", &month, &year);

	printf("%d年%d月有%d天\n", year, month, dayOfMonth(month, year));



	return 0;
}


//
int dayOfMonth(int m ,int y )
{
	switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return 28+isLeap(y);
		default:
				return -1;
	}
}



// 给定一个年份，判断是否为闰年
int isLeap(int y)
{
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}
*/



/*
// 键盘输入n    求n以内的完数

#include<stdio.h>

int main(void)
{
	int n,i,j,sum = 0,m = 0;
	printf("请输入n：\n");
	scanf("%d", &n);
	for(i = 1 ; i < n ; i++)
	{
		sum = 0;
		for(j = 1 ; j< i ; j++)
		{
			if(i%j ==0 )
			sum = sum + j;
		}	
		if(i == sum)
		{
			m++;
			printf("这是一个完数 ：%d\n", i);

		}
	}
	
	printf("完数有 %d 个 \n", m);

	return 0;
}
*/
/*
//完数   用函数调用
#include<stdio.h>

int wanshu(int num);

int main(void)
{
	int res;
	for(int i = 1 ;  i < 100 ; i++)
	{
		res = wanshu(i);
		if(res)
		{
			printf("%d 这是一个完数\n", i);
		}

	}


	return 0;
}

int wanshu(int num)
{
		int s = 0;

		for (int i = 1; i < num; i++)
				if (num % i == 0)
						s += i;
		if (s == num)
				return 1;
		else
				return 0;

}
*/











/*
//打印  乘法表

#include<stdio.h>

int main(void)
{
	int h,l,n;
	for(h = 1 ; h <= 9 ; h++)
	{
		for(n = 1 ; n < h ; n++)
				printf("         ");
		for(l = h ; l <= 9 ; l++)
		{
			printf("%d*%d=%2d   ", h,l,h*l);

		}
		printf("\n");

	}

	return 0;
}
*/

/*
//  输入年月日， 输出这是这一年的第几天

#include<stdio.h>

int main(void)
{
	int y,m,d,i;
	int sum = 0;

	printf("请输入年月日：");

	scanf("%d%d%d", &y,&i,&d);
	for( m = 1 ; m < i ; m++)
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
	printf("这是%d年第%d天 \n", y,sum);
	return 0;
}
*/







