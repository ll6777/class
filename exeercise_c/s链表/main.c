#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist.h"

static void showInt(const void *data)
{
	const int *d = data;
	printf("%d\n", *d);

}

int main(void)
{
	seqlist_t  *mylist;
	mylist = seqlistInit(sizeof(int));

	for(int i = 1; i <= 20 ; i += 2)
	{
		seqlistInesert(mylist, &i);

	}
	seqlisTraval(mylist, showInt);
	

	return 0;
}














