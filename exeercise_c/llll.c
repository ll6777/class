/*  //爱因斯坦阶梯问题
#include<stdio.h>
int main()
{
	int a = 0 ;
	for(a = 0 ;   ;a++)
	{

	if(a%2 ==1 && a%3 ==2 && a%5 ==4 &&  a%6 ==5 && a%7 == 0)
	{		

	printf("%d\n ", a);
	break;
	}
	}

	return 0;

}

*/


/*  //小球从100米高空下落，每次回弹之前的一半，若输入下落次数，求回弹高度
#include<stdio.h>


//100   1 50  2  25  3  12.5  4  6.25
int main()
{
	int n,i;
	float m = 100;
	printf("请输入下落次数：");
	scanf("%d", &n);
	for(i = 0 ;i < n ; i++ )
	{
	m = m/2;

	}
	printf("%f", m);

	return 0;
}
*/


/* //每个人相差2岁，第一个人10岁，求第5个人年龄
#include<stdio.h>
int main()
{
	int i = 0,a = 10;
	for(i ;i<4 ;i++ )
	{
		a = a+2;

	}
	printf("第5个人年龄为：%d\n", a);



	return 0;
}
*/
  //键盘输入字符串，将小写转换为大写。
#include<stdio.h>

int main()
{
	char ch;
	FILE *pfile = NULL;
	char filename[20];
	printf("请输入一串字符：");
	gets(filename);
	if()





	return 0;
}



















