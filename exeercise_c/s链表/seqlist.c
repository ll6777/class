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

void *seqlistFind(const seqlist_t *s, const void *key,cmp_t cmp)    //查找
{
	for(int i = 0; i < s->nmemb; i++)
	{
		if(cmp((char *)s->arr +i * s->size, key) == 0)
			return (char *)s->arr + i * s->size;

	}
	return NULL;
}

int seqlistDelete(seqlist_t *s, const void *key, cmp_t cmp)   //删除
{
	int i;
	for( i = 0; i < s->nmemb; i++)
	{
		if(cmp((char *)s->arr +i * s->size, key) == 0)
		{
			memcpy((char *)s->arr + i * s->size,(char *)s->arr + (i+1)*s->size,(s->nmemb-i-1)*s->size );
			break;
		}
	}
	if(i == s->nmemb)
=		return -1;
	s->nmemb --;
	s->arr = realloc(s->arr,s->nmemb * s->size);

	return 1;
}


int seqlistUpdate(const seqlist_t *s, const void *key, cmp_t cmp, const void *newdata)   //修改
{
	int i;
	for( i = 0; i < s->nmemb; i++)
	{
		if(cmp((char *)s->arr +i * s->size, key) == 0)
		{
			memcpy((char *)s->arr + i * s->size,(char *)newdata,s->size * sizeof(char) );
			break;
		}
	}
	if(i == s->nmemb)
		return -1;
	return 0;
}

void seqlistDestroy(seqlist_t *s)  //销毁
{
	free(s->arr);
	free(s);
	
}





