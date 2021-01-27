/*
//字符数组 //
#include<stdio.h>

int changdu(char *str);

int main(void)
{
	char str[20] = "hello world";
	char str1[] = {'h','e','l','l','o','\0'};
	char str2[] = {"hello"};
	char str3[5] = {'h','e','l','l','o'};  //字符串  
	    //char str 5[5] = "hello";  //错误写法 

	int i, sum = 0;
	for(i = 0 ; str[i] != '\0'; i++){
		putchar(str[i]);      //printf("%c",  str[i]);	

	}
	printf("\n");
	printf("一共有%d个字符\n", changdu(str));

	return 0;
}

int changdu(char *str)
{

	int i,sum = 0;
	for(i = 0 ; str[i] != '\0'; i++){
		sum++;
	}
	return sum;
}

*/





//复制  字符串

#include<stdio.h>

char  *mystrcpy(char *dest, char *src);

int main(void)
{
	
	char src[20] = "hello world";
	char dest[20] = {};
	*mystrcpy((dest),(src));

	for(int i = 0 ; dest[i] != '\0'; i++)
		putchar(dest[i]);     
	printf("\n");

	return 0;
}

char  *mystrcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
			dest[i] = src[i];
	
	return dest;





}

















