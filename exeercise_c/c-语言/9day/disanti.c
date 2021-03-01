#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int a, int b)
{
	return a + b;
}

int del(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int divi(int a, int b)
{
	return a / b;
}

int op(int a, int b, int (*p)(int, int))
{
	return p(a, b);
}


int main(int argc, char *argv[])
{
	int res, left, right;

	if (argc < 4)
		return 1;
	// 字符串转整型函数atoi(3)
	left = atoi(argv[1]);	
	right = atoi(argv[3]);
	
	if (!strcmp(argv[2], "+"))
		printf("%d + %d = %d\n", left, right, op(left, right, add));
	else if (!strcmp(argv[2], "-"))
		printf("%d - %d = %d\n", left, right, op(left, right, del));
	else if (!strcmp(argv[2], "x"))
		printf("%d * %d = %d\n", left, right, op(left, right, mul));
	else if (!strcmp(argv[2], "/"))
		printf("%d / %d = %d\n", left, right, op(left, right, divi));

	return 0;
}






