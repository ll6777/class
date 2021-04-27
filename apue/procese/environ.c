//显示全局变量
#include<stdio.h>
#include<stdlib.h>

extern char **environ;

int main(void)
{
/*	for(int i = 0; environ[i] ; i++)
	{
		puts(environ[i]);
	}*/

	char *p = getenv("PATH");
	puts(p);
	setenv("PATH" , "123" , 1);
	
	p = getenv("PATH");
	puts(p);


	return 0;
}
