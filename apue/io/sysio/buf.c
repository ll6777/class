#include<stdio.h>
#include<unistd.h>

int main(void)
{
	printf("hello   ");
	fflush(NULL);
	printf("world   ");
	fprintf("i am  error");	

	write(1 , "good" , 4);
	write(1 ,  "moring" , 7);
	return 0;
}





