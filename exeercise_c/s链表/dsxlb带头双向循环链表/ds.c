#include<stdio.h>
#include<stdlib.h>
#include"ds.h"
#include<string.h>

int listheadInit(int size , listhead_t **l)   //初始化
{
	listhead_t *h;
	h = malloc(sizeof(listhead_t));
	if(h ==  NULL)
		return -1;
//	h->head.data = NULL;

	h->head.next = &h->head;
	h->head.prove = &h->head;
	h->size = size;
	h->nmemb = 0;
	*l = h;

	return 0;
}
int listInsert(listhead_t *l , const void *data, int way)  //增加
{
	node_t *new;
	node_t *p;

	new = malloc(sizeof(node_t)+l->size);
	if (NULL == new)
		return -1;
//	new->data = malloc(l->size);
	

	memcpy(new->data, data, l->size);
	if (way == HEADINSERT) {     //头部插入
		new->next = l->head.next;
		new->prove = &l->head;
		}
	else if (way == TAILINSERT) {    //尾部插入
		for (p = l->head.next; p->next != &l->head; p = p->next)
			;
		new->prove = p->prove;
		new->next = p;
	}
		new->next->prove = new;
		new->prove->next = new;

	return 0;
}
void listTraval(const listhead_t *l ,pri_t pri)  //遍历
{
	node_t *p;

	for (p = l->head.next; p != &l->head; p = p->next) {
		pri(p->data);
	}
}
	
void *listSearch(const listhead_t *l, const void *key, cmp_t cmp)    //查找
{
	node_t *p;
	for(p = l->head.next ; p != &l->head ;  p = p->next )
		if(cmp(p->data,key) == 0)
		break;

	return p;

}
int listDelete(listhead_t *l, const void *key, cmp_t cmp)    /*删除*/
{
	node_t *p;
	p = listSearch(l, key, cmp);
	if( p == &l->head)
		return -1;

	p->next->prove = p->prove;
	p->prove->next = p->next;
	free(p);
	return 0;
}


void *listFetch(listhead_t *l, const void *key, cmp_t cmp)   //摘除:删掉指定结点的同时获得数据
{
	node_t *p;
	void *y;
	p = listSearch(l,key,cmp);
	if(p == &l->head)
		return NULL;
	
	y = p->data;
	p->next->prove = p->prove;
	p->prove->next = p->next;
	free(p);

	return y;
}

int listIsEmpty(const listhead_t *l)   //是否为空
{
	if(l->head.next == &l->head)
		return 0;
	else
		return 1;

}
void listDestroy(listhead_t *l)    //销毁
{
	node_t *p,*k;
	for(p = l->head.next ; p != &l->head ; )
	{
		k = p;
		p = p->next;
		free(k);
	}
	free(l);	
}





