#include<stdlib.h>
#include<string.h>
#include"seqlist.h"


seqlist_t *seqlistInit(int size)    //初始化顺序表
{
	seqlist_t *s;
	s = malloc(sizeof(seqlist_t));
	if(s == NULL)
		return NULL;
	s->arr = NULL;
	s->size = size;
	s->nmemb = 0;

	return s;
}


int seqlistInesert(seqlist_t *s, const void *data)   //增加新元素
{
	s->arr = realloc(s->arr,(s->nmemb+1)*s->size);
	if(NULL == s->arr)
		return -1;
	memcpy((char *)s->arr+s->nmemb*s->size,data,s->size);
	s->nmemb ++;

	return 0;
}



void seqlisTraval(const  seqlist_t *s, void(*pri)(const void *data))   //遍历
{
	for(int i =0 ; i < s->nmemb ; i++)
	{
		pri((char *)s->arr+i*s->size);

	}





}

















