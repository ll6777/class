/*
1. 写一段代码，向终端打印
    *
  * * *
* * * * *

2. 读入两个整型数,计算两个整型数的乘积，并打印输出

3. 读入用户输入的年份，判断是否为闰年

4. 读入一个月份, 判断输入哪个季节

*/




/*
#include<stdio.h>

int main(void)
{
	printf("    *    \n");	
	printf("  * * *  \n");
	printf("* * * * *\n");


	return 0;
}
*/

/*
#include<stdio.h>

int main()
{
	int a,b,c;
	printf("请输入两个要相乘的整数：");

	scanf("%d%d", &a,&b);
	c = a * b;
	printf("%d\n", c);

	return 0;
}
*/



#include<stdio.h>

int main(void)
{
	int n;
	printf("请输入年份：");

	scanf("%d", &n);
	if(n%4 == 0 && n%100 != 0 || n%400 == 0)
		printf("闰年\n");
	else	
		printf("平年\n");


	return 0;
}

/*
#include<stdio.h>

int main(void)
{
	int n;
	printf("输入1--12某个月份：");

	 scanf("%d", &n);

	if(n >= 3 && n <= 5)
		printf("春天");
	
	else if(n >= 6 && n <= 8)
		printf("夏天");

	else if(n >= 9 && n <= 11)
		printf("秋天");

	else if(n == 1 || n == 2 || n == 12)
		printf("冬天");
	else
		printf("错误");

	return 0;
}
*/




