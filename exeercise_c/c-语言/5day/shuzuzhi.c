
#include<stdio.h>


int maxarray(int *p, int n)

int main(void)
{
	int a[7] = {3,2,6,9,5,4,7};
	int i;
	for(i = 0 ; i < 7 ; i++)
	{
		

	}



	return 0;
}



int maxarray(int *p, int n)
{
	int i,max;
	max = p[0];
	for(i = 1 ; i < n ; i++)
	{
		if(max < *(p+i))
		{
			max = p[i];
		}
	}

	return max;



}



















