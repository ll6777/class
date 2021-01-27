//定义一个函数   将给定的字符串中的大写字母转小写字母   小写字母转大写，将转换完的的字符串返回
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	strcpy(str2,str);
	for(int i = 0; str2[i] != '\0' ; i++)
	{
		if(str2[i] < 91 && str2[i] > 64)
				str2[i] += 32;
		else if (str2[i] < 123 && str2[i] > 96)
				str2[i] -= 32;
	}
	return str2;
}

















