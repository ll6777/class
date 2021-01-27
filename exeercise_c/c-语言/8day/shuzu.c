/*
//去除多余空格
#include<stdio.h>
char *shanchu(char *a,char *b);

int main(void)
{
	char a[100] = "        abcdefgdddd          ";
	char b[100] = { };
	shanchu(a,b);
	puts(b);
	printf("\n");

	return 0;
}

char *shanchu(char *a,char *b)
{
	int j = 0;
	for(int i = 0;i<100;i++)
	{
		if(a[i] != ' '  )
		{
			b[j] = a[i];
			j++;
		}	
	}
	b[j] = '\0';
	return b;

}
*/

/*2、有一个字符串”1a2b3d4z”,；
要求写一个函数实现如下功能，
功能1：把偶数位字符挑选出来，组成一个字符串1。
功能2：把奇数位字符挑选出来，组成一个字符串2，
功能3：把字符串1和字符串2拼接组成一个新的字符串，返回。*/


/*
#include<stdio.h>
#include<string.h>
char *suoyouzimu(char *a,char *a1);
char *suoyoushuzi(char *a,char *a2);

int main(void)
{
	char a[100] = "1a2b3d4z";
	char a1[100] = { };  //所有字母
	char a2[100] = { };  //所有数字
	char a3[100] = { };  //a1+a2

	puts(suoyouzimu(a,a1));
	puts(suoyoushuzi(a,a2));
	puts (strcat(a1,a2));
	return 0;
}

char *suoyouzimu(char *a, char *a1)
{
	int i,j = 0;
	for(i = 0 ; a[i] ; i++)
	{
		if(i%2 != 0)
		{
			a1[j] = a[i];
			j++;
		}
	}
	a1[j] = '\0';
	return a1;
}
char *suoyoushuzi(char *a,char *a2)
{
	int i,j = 0;
	for(i = 0 ; a[i] ; i=i+2)
	{
		a2[j] = a[i];
		j++;
		
	}
	a2[j] = '\0';
	return a2;
}


char *zimushuzi(char *a,char *a2)
{
	int i,j = 0;
	for(i = 0 ; a[i] ; i=i+2)
	{
		a2[j] = a[i];
		j++;
		
	}
	a2[j] = '\0';
	return a2;
}
*/


/*
//3、c语言中有一个函数strchr(3)的功能是在字符串中找指定的字符，尝试自己定义一个函数实现其功能

#include<stdio.h>
#include<string.h>

char chazhaozifu(char *a,char n);

int main(void)
{
	char a[] = "1234567890q43342342342wertyuiopasdfghjklzxcvbnm";
	char n;
	puts (a);
	printf("请输入要查找的字符： ");
	scanf("%c", &n);
	chazhaozifu(a,n);

	return 0;
}

char chazhaozifu(char *a,char n)
{
	int i;
	for(i = 0 ; a[i] ; i++)
	{
		if(a[i] == n)
		{
			printf("所查字符在数组%d下标位置\n",i);

		}
	}

}
*/

//4、c语言中有一个函数strstr(3)的功能是在字符串中找子串，尝试自己定义一个函数实现其功能
/*

#include<stdio.h>
#include<string.h>

char chazhaozifu(char *a,char *b);

int main(void)
{
	char a[] = "1234567890q43342342342wertyuiopasdfghjklzxcvbnm";
	char b[] = "4334";
	puts (a);
	puts (b);

	chazhaozifu(a,b);

	return 0;
}

char chazhaozifu(char *a,char *b)
{
	int i,j = 0;
	for(i = 0 ; a[i] ; i++)
	{
		if(a[i] == b[j])
		{
			while(b[j])
			{
				i++;
				j++;
				if(a[i] == b[j]);
				printf("所查字符在数组%d下标位置\n",i);
			}
		}
		else
			printf("查找不到\n");

	}

}
*/



//5、数学中有个杨辉三角的概念，打印杨辉三角的前10行

#include<stdio.h>


int main(void)
{
	int 




 return 0;
}
















