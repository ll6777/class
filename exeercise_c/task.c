//判断一个数字的奇数还是偶数

#include<stdio.h>

int main()
{
	int num;

	scanf("%d",&num);

	if(num % 2 == 0 )
	{
		printf("%d 是一个偶数\n",num);
	}
	else
	 	printf("%d 是一个奇数\n",num);


	 return 0;

	

	

}
