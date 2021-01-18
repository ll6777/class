#include<stdio.h>

int main(void)
{
//	printf("早上好！\n");
	
//	printf("hello word\n");

//	printf("hello\b word\n");
	
//	printf("hello\t word\n");
	
//	printf("hello w\rord\n");

	char ch1 = 'a';
	int var;
	float f = 1.9;

	var = ch1;
	printf("%d\n",var);
	
	printf("%d\n",var + ch1);
//	printf("%f\n", f + ch1);

	printf("%d\n", (int)f+1);
	




	int a = 15,b,c;
	b = a >> 1;
	c = a << 1;
	printf("%d    %d",b, c);

















	printf("char: %ld个字节\n", sizeof(char));
	printf("int: %ld个字节\n", sizeof(int));
	printf("short: %ld个字节\n", sizeof(short));
	printf("double: %ld个字节\n", sizeof(double));
	printf("float: %ld个字节\n", sizeof(float));
	printf("long: %ld个字节\n", sizeof(long));
	printf("long long: %ld个字节\n", sizeof(long long));


	return 0;
}
