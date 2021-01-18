/*
   已知1990.1.1是星期1,读入用户输入的1990后的日期，
   打印相应的日历
   ./mycal 
   2008/3
   三月 2008         
   日 一 二 三 四 五 六  
   					 1  
   2  3  4  5  6  7  8  
   9 10 11 12 13 14 15  
   16 17 18 19 20 21 22  
   23 24 25 26 27 28 29  
   30 31           

   1990.1.1~2008.3.1总天数 % 7 == 2008.3.1星期几
   总天数==1990~2008不包括2008总天数+2008.1.1~2008.3.1

 */





#include<stdio.h>

int isLeap(int y);  // 声明函数    判断是否是闰年

int daymonth(int m,int y); //定义函数    判断月份的天数

int main(void)
{
	int y,m,d,i;
	int sum = 0,day = 1,n = 0,month=0;

	printf("请输入年月：");

	scanf("%d%d", &y,&m);

	for(i = 1990 ; i < y ; i++)
	{		
		sum = sum +365+isLeap(i);
	}
	for(i = 1 ; i < m ; i++)//加上输入月份之前天数
	{	
			sum = sum + daymonth(i, y);
	}

	//循环结束i == m 给m赋值
	month =daymonth(m,y);

	sum = (sum + 1) % 7;
	
	printf("     %d月     %d年\n", m,y);
	printf(" 日 一 二 三 四 五 六\n");

	for(sum ; sum > 0 ; sum--)//有多少就输入多少空格
	{
		printf("   ");
		n++;
	}
	for(day ; day <= month ; day++)
	{
		printf("%3d", day);//从1号开始输出
		n++;//n判断星期几
	
		if(n == 7)
		{
			n = 0;
			printf("\n");
		}
		if(day == month)
				printf("\n");
	}
	return 0;
}

//定义函数

int isLeap(int y)  //判断是否是闰年
{
	if(y%4 == 0 && y%100 != 0 || y%400 == 0)
	{
		return 1;//闰年366
	}	
	else return 0;//平年365

}

int daymonth(int m,int y) //定义函数    判断月份的天数
{
	int res;
		if(m == 1 || m == 3 || m == 5 || m == 7 || \
						m ==8 || m==10 || m==12)
			res = 31;
		else if(m == 4 || m == 6 || m == 9 || m == 11)
			res = 30;
		else  res = 28 + isLeap(y);
	return res;	
}







































