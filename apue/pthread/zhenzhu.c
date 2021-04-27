#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int a[10] = {};

	for(int i = 1 ; i < 1000 ; i++)
		for(int j = 1 ; j < 1000 ; j++)
			for(int k = 1 ; k < 1000 ; k++)
				for(int l = 1 ; l < 1000 ; l++)
					for(int m = 1 ; m < 1000 ; m++)
						for(int n = 1 ; n < 1000 ; n++)
							for(int o = 1 ; o < 1000 ; o++)
								for(int p = 1 ; p < 1000 ; p++)
									for(int q = 1 ; q < 1000 ; q++)
										for(int r = 1 ; r < 1000 ; r++)
											if((i+j+k+l+m+n+o+p+q+r) == 1000 && i!=j && j!=k && k!=l && l!=m && m!=n && n!=o && o!=p && p!=q){
												printf("%d %d %d %d %d %d %d %d %d %d\n",i,j,k,l,m,n,o,p,q,r);
											}



	return 0;
}















