/*
//定义一个函数，将给定的字符串中的小写字符组成新的字符串返回
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *reverseString(const char *str);
int main(void)
{
	char a[] = "abcdefgHIJKLMN";
	
	puts(reverseString(a));



	return 0;
}


char *reverseString(const char *str)
{
	char *str2 = calloc(strlen(str) + 1,sizeof(char));
	char *str3 = calloc(strlen(str) + 1,sizeof(char));
	strcpy(str2,str);
	int j = 0;
	for(int i = 0; str2[i] != '\0' ; i++)
	{
		if(str2[i] < 123 && str2[i] > 96)
			str3[j] = str2[i];
		j++;
	}
	return str3;
}
*/




//2. 有一个数组，空间是堆空间，定义一下三个函数
//<1> 向动态数组中增加一个新的元素
//<2>从动态数组中删除指定元素
//<3>查找数组中的指定元素


#include<stdio.h>
#include<stdlib.h>
#include<string.h>





int main(void)
{
//	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int n;
//	for(int i = 0 ; a[i] != '\0' ; i++ )
//		printf("原数组为：%d   \n",a[i]);

	printf("请输入要添加的新元素  \n");
	scanf("%d",&n);
	addyuansu(n);
	





	return 0;
}

int addyuansu(int *p ,int n )
{
	int *q;
	int t;
	t = sizeof(q)/sizeof(int);
	q = calloc(sizeof(int)*5);

	if(q == NULL)
		return NULL;
	strcpy



}



	
	//int *p = (int*)malloc(size_t(sizeof))




/*
//四则运算 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{
	int a,b,sum = 0;
	char c;
	char *p;
	for(int i = 1 ; i <argc ; i++)
	{
		if(i == 1 ){
			p = argv[i];
			a = *p-48;
		}
		if(i == 3 ){
			p = argv[i];
			b = *p-48;
		}
		if(i == 2 ){
			p = argv[i];
			c = *p;
		}
	}

	if(c == '+')
		printf("%d+%d=%d\n",a,b,a+b);


	if(c == '-')
		printf("%d-%d=%d\n",a,b,a-b);

	if(c == 'x')
		printf("%d*%d=%d\n",a,b,a*b);

	if(c == '/')
		printf("%d/%d=%d\n",a,b,a/b);
}

*/







#include <stdio.h>
#include <string.h>

void reverseString(char *p);
void deleteSpaceString(char *p);
void test(char *p, void (*f)(char *));
int main(void)
{
	char str[] = "hello world boys";

	test(str, reverseString);
	printf("%s\n", str);

	test(str, deleteSpaceString);
	printf("%s\n", str);

	return 0;
}

// 将给定的字符串逆序返回
void reverseString(char *p)
{
	int i, j;
	char ch;

	for (i = 0, j = strlen(p)-1; i < j; i++, j--){
		ch = p[i];
		p[i] = p[j];
		p[j] = ch;
	}
}

// 将字符串的空格删除
void deleteSpaceString(char *p)
{
	char *ret;
	while (1) {
		ret = strchr(p, ' ');
		if (ret == NULL)
			break;
		strcpy(ret, ret+1);
	}
}

// f-->函数指针
void test(char *p, void (*f)(char *))
{
	f(p);
}







