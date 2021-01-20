
#include<stdio.h>

#define  NUM  10
#define  SQUARE(X)     (X)*(X)
#define  SWAP(X,Y) \
		do{typeof(x)  t ; t = x; x = y; y = t}while(0);

int main(void)
{
	int i,score;
	int m = 20, n = 10;

	printf("123456\n");

	scanf("%d", &i);
	printf("%d \n", SQUARE(i));

	printf("m = %d    n = %d  \n", SWAP(m,n));


//	printf("%d   ", score);


	return 0;
}




