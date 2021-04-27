#include<stdio.h>
#include<setjmp.h>
#include<stdlib.h>

jmp_buf env;

static int div2(int a, int b)
{
	if(b == 0){
		longjmp(env , 1);
	}
	return a/b ;

}




int main(void)
{
	int m,n;
	
	if(setjmp(env) == 0){
		printf("请输入两个数：\n");
	}else
		printf("请重新输入两个数：\n");
	scanf("%d%d" , &m,&n);

	printf("%d\n", div2(m, n));


	exit(0);
}









