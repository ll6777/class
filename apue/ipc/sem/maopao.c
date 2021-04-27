#include<stdio.h>
#include<stdlib.h>




int main(void)
{
	int a[10] = {1,3,2,4,0,6,5,7,8,9};
	int i,j,k,t;

	for(i = 0 ; i < 9; i++)
	{
		for( j = 0 ; j < i - 1 ; j++)
		{
			if(a[j] > a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}

		}

	}

	for( k = 0 ; k < 10 ; k++){
		printf("%d  " , a[k]);

	}
		printf("\n");

	return 0;
}




















