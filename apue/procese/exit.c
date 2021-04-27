#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void test(void)
{
	exit(0);
}
int hand1(void)
{
	printf("hand 1");
}

int hand2(void)
{
	printf("hand 2");
}

int hand3(void)
{
	printf("hand 3");
}

int main(void)
{
//	test();
	printf("hello world !");
	atexit(hand1);
	atexit(hand2);
	atexit(hand3);


	exit(EXIT_SUCCESS);
//	_exit(EXIT_SUCCESS);


}














