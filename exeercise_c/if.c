/*   c语言50道练习题
#include<stdio.h>


int main(void)
{
	int num;
	
	printf("请输入你的成绩：");

	scanf("%d", &num);

	if(num >= 90 && num <=100)
	{
		printf("你的成绩优秀\n");
	}

	else if(num >= 80 && num <90)
	{
		printf("你的成绩良好\n");
	}

	else if(num >= 70 && num <80)
	{
		printf("你的成绩还行\n");
	}

	else if(num >= 60 && num <70)
	{
		printf("你的成绩及格\n");
	}

	else if(num >= 0 && num <60)
	{
		printf("你的成绩不及格\n");
	}

	else 
	{
		printf("你输入的成绩无效\n");
	}
	return 0;
}
*/


//要将5张100，换成50 20 10 5 每张最少一张   求需要多少张纸币

#include<stdio.h>




/*

//50a+20b+10c+5d ==500

int main(void)
{
	int a=1,b=1,c=1,d=1;
	for(a = 1 ; a < 10 ; a++)
	{
		for(b = 1 ;b < 22   ;   b++)
		{
			for(c = 1 ; c < 43  ;  c++)
			{
				for(d = 1 ; d < 85  ; d++)
				{
				
					if(50*a + 20*b + 10*c +5*d ==500)	
						printf("50：%d 20：%d 10：%d 5：%d 合：%d\n",a,b,c,d,(a+b+c+d));

				}
					
			}

		}
	}

	return 0;	
}
*/

/*

//找车牌号  
#include<stdio.h>

int main(void)
{
	int i,j;
	int a= 0,b= 0,c= 0,d= 0;
	for(i = 1100; i < 9988 ;i++ )
	{
		for(j = 1 ;j < 100 ; j++)
		{	
			a = i/1000;
			b = (i%1000)/100;
			c = (i%100)/10;
			d = (i%10);

			if(j*j == i &&  a == b && c == d && a != c) 
				printf("车牌号为：%d \n", i);
		}

	}

	return 0;
}
*/
/*
//找100--200之间的完全平方数
#include<stdio.h>

int main()
{
	int i,j;
	for(i = 100; i < 200 ; i++ )
		for(j = 1 ; j < 15 ; j++)
				if(j*j == i)
					printf("完全平方数有%d   = %d * %d\n", i,j,j);

	return 0;
}
*/
/*
//找出三位自然数中的所有素数，要求判断x素数用自定义函数data(x)实现。
#include<stdio.h>


void data();
int main(void)
{
	data();



	return 0;
}


void data()
{
	int i,num,a,sum = 0;
	for(num = 100 ; num < 1000 ; num++)
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
			printf("%d 这是一个素数\n", num);
			sum++;

		}

	}
	printf("一共有%d个素数\n",sum);

}
*/










/*
//“百钱百鸡”问题。百钱买百鸡，鸡翁一值钱三，鸡母一值钱二，鸡雏三值钱一，问鸡翁、鸡母、鸡雏各几何？

#include<stdio.h>

int main(void)
{

	int a=0,b=0,c=0;
	for(a = 0 ; a < 34 ; a++)
	{
		for(b = 0 ;b < 51   ;   b++)
		{
			for(c = 0 ; c < 100  ;  c = c+3)
			{	
				if((3*a + 2*b + 1/3*c) == 100  &&  (a+b+c) == 100   && c % 3 == 0 )	
					printf("公鸡：%d只， 母鸡：%d只， 小鸡：%d只，  一共：%d只\n",a,b,c,(a+b+c));
			}

		}

	}

	return 0;
}
*/

/*
//猴子摘桃子num个  第一天吃一半又多吃一个，  第二天一样，  第10天就剩1 个   求num；

#include<stdio.h>

int main(void)
{
	int num = 1,i;

	for(i = 1 ;  i < 10 ; i++ )  //第10天就循环9次
		{
			num =  (num+1)*2 ;
			
		}
	printf("第一天摘桃子 %d 个\n",num);


	return 0;
}
*/


/*
//计算1+2+3…+n的值，n是从键盘输入的自然数。

#include<stdio.h>
int main(void)
{
	int n,i,sum = 0;
	printf("请输入要求的到n的值：");

	scanf("%d", &n);

	for(i = 1; i < n+1 ;  i++)
	{
		sum = sum + i ;

	}
	
	printf("1+2+3+....+%d  == %d\n",n,sum);


	return 0;
}
*/


/*
//sqrt   求n以内（不包括n）同时能被3和7整除的所有自然数之和的平方根s，n从键盘输入。例如若n为1000时，函数值应为：s=153.909064。
// gcc 的时候  加 -lm  


#include<stdio.h>

#include<math.h>
int main(void)
{
	int i,n,sum = 0;
	float s = 0;
	printf("请输入n是多少：");

	scanf("%d",&n);

	for(i =1 ; i < n  ;  i++)
	{
		if(i % 3 == 0  && i % 7 == 0  )
		{
			sum = sum +i;

		}

	}
	s = sqrt(sum);
	printf("函数值应为： s = %f \n",s);
	

	return 0;
}
*/

/*
//  从终端（键盘）读入20个数据到数组中，统计其中正数的个数，并计算这些正数之和。

#include<stdio.h>	

int main(void)
{
	int i,a[20] = { }, sum = 0;
	printf("请输入20个数据： ");
	for(i =0; i<= 19  ; i++)
	{
		scanf("%d",&a[i]);
		if(a[i] > 0 )
			sum = sum +a[i];
	} 	
	
	for(i = 0 ; i <= 19 ; i++)
	
	{	
		printf("%d  ",a[i]);
	}
	printf("所有正数合为：%d \n",sum);
	return 0;
}
*/

/*
//从终端（键盘）将5个整数输入到数组a中，然后将a逆序复制到数组b中，并输出b中各元素的值。

#include<stdio.h>

int main(void)
{ 
	int i,j,t,a[5] = { },b[5] = { }, sum = 0;
	printf("请输入5个数据： ");
	for(i =0; i<= 4  ; i++)
	{
		scanf("%d",&a[i]);
		
	} 	
	
	for(i = 0 ,j =4 ; i < 5 ; i++,j--)
	{	
		b[j] = a[i];
	}
	for(j =0 ;j<5 ;j++)
	{
		printf("%d  ", b[j]);
	}
	printf("\n");
	return 0;
}
*/

/*
//8.输入1~10之间的一个数字，输出它对应的英文单词。

#include<stdio.h>
#include<math.h>

int main(void)
{
	int num,t;
	char a[10] = {'a','b','c','d','e','f','g','h','i','j'};
	printf("请输入1～10之间的一个数字：");
	scanf("%d", &num);
	t = num -1;
	printf("%c\n", a[t]);




	printf("\n");
	
	return 0;
}
*/


/*
//13.输入某三角形的三个边的长度，判断出这是个什么三角形（等腰、等边、任意，或不能构成）。

#include<stdio.h>

int main(void)
{	
	int a,b,c;
	printf("请输入三角形的三条边：");
	scanf("%d%d%d",&a,&b,&c);
	if(a+b>c && a+c>b && b+c>a && a-b<c && a-c<b &&  b-c<a)
	{
		if(a == b && a!=c)
			printf("这是一个等腰三角形\n");
		else if(a == b &&  b == c)
			printf("这是一个等边三角形\n");

		else if(a*a + b*b == c*c)
			printf("这是一个直角三角形\n");
		else 
			printf("这是一个其他三角形\n");

	}
	else printf("你输入的三条边无法构成三角形\n");


	return 0;
}
*/
/*
//14.输入10个数，分别统计其中正数、负数、零的个数。

#include<stdio.h>

int main(void)
{
	int i,a[10] = { }, sum = 0,n = 0,l = 0;
	printf("请输入10个数据： ");
	for(i =0; i<= 9  ; i++)
	{
		scanf("%d",&a[i]);
		if(a[i] > 0 )
		{	
			sum++;
		printf("正数有：%d\n",a[i]);
		}
		else if(a[i] < 0)
		{
			n++;
		printf("负数有：%d\n",a[i]);
		}
		else if(a[i] == 0)
			l++;
	} 	
	
	printf("所有正数一共有%d个 \n",sum);
	printf("所有负数一共有%d个 \n",n);
	printf("所有零一共有%d个 \n",l);
	return 0;
}
*/
/*
//15.先随机产生N个三位自然数输出，然后再输出其中同时是3、5、7倍数的数。（设N为100）

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i,a[100]= { };
	for(i = 0 ; i<100 ; i++)
	{
		a[i] = 100 + rand()%1000;

	}
	for(i = 0 ; i<100 ; i++)
	{
		if(a[i]%3==0 && a[i]%5==0 && a[i]%7==0)
				printf("%d\n",a[i]);

	}
	

	return 0;
}
*/
/*
//22.输出n行由“#”组成的矩形，每行“#”的个数为m个，其中n、m由终端（键盘）输入。要求输出m个“#”功能由函数satr(m)函数实现。
#include<stdio.h>

int main(void)
{
	int n



	return 0;
}
*/

//找100--2000之间的完全平方数
#include<stdio.h>

int main()
{
	int i,j;
	for(i = 100; i < 2000 ; i++ )
		for(j = 1 ; j < 45 ; j++)
				if(j*j == i)
					printf("完全平方数有%d   = %d * %d\n", i,j,j);

	return 0;
}





































































