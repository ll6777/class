#include <stdio.h>

int main()
{
   int a[4] = {1,2,3,4};
	int i,j,k,l;
	int sum = 0;
	for(i = 0 ; i < 4 ; i++){
		for(j = 0 ; j < 4 ; j++){
			for(k = 0 ; k < 4 ; k++){
				for(l = 0 ; l < 4 ; l++){
					if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l){
						printf("%d %d %d %d \n", a[i],a[j],a[k],a[l]);
						sum++;
					}
				}
			}
		}
	}
   printf("一共有 %d 种排列组合\n", sum);



   int b;
   while(b++ <10);
	printf("b = %d", b);
   return 0;
}
