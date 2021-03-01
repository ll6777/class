/*
//输出两个数中的最大值

#include<stdio.h>

int max(int x,int y)
{
	int z;
	z = x > y? x:y;
	return z;
}

int main(void)
{
	int a,b,c;
	printf("input two number: \n");
	scanf("%d%d",&a,&b);
	c = max(a,b);
	printf("max is %d\n",c);

	return 0;
}
*/


/*
//判断素数
#include<stdio.h>

int isprime(int num)
{
	int flag = 1,i;
	for(i = 2; i<=num/2; i++)
		if(num%i == 0)
				flag = 0;
	return(flag);

}

int main(void)
{
	int n;
	printf("input an  integer\n");
	scanf("%d",&n);
	if(isprime(n))
		printf("%d  is a primc",n);
	else
		printf("%d  is not a primc",n);
	printf("\n");
		


	return 0;
}
*/



/*
//递归解决年龄问题
#include<stdio.h>

int age(int n)
{
	int f;
	if(n==1)
		f=10;
	else
		f=age(n-1)+2;
	return f;
}

int main(void)
{
	int i,j;
	printf("Do you want to know whose age? Please input:\n");
	scanf("%d", &i);
	j = age(i);
	printf("the age is %d\n",j);

	return 0;
}
*/




/*
//递归解决分鱼问题

#include<stdio.h>

int sub(int n)
{
	if(n==0)
		{
			static int i=0;
			do
			{
				i++;
			}
			while(i%5!=0);
			return(i+1);
		}
	else
	{
		int t;
		do
		{
			t = sub(n-1);
		}
		while(t%4!=0);
		return(t/4*5+1);
	}
}

int main(void)
{
	int total;
	total=sub(5);
	printf("the total number of fish is %d\n",total);

	return 0;
}
*/




//小数分离

#include<stdio.h>
#include<math.h>

int main(void)
{
	float number;
	double f,i;
	printf("input the number:\n");
	scanf("%f",&number);
	f=modf(number,&i);
	printf("%f=%f+%f",number,i,f);

	return 0;
}
	
































