#include "list.h"
#include<stdlib.h>
#include<string.h>




int listheadInit(int size, listhead_t **l )   //初始化头结点
{
	listhead_t *h;

	h = malloc(sizeof(listhead_t));
	if (NULL == h)
		return -1;

	h->next = NULL;
	h->size = size;
	h->nmemb = 0;

	*l = h;

	return 0;
}

int listInsert(listhead_t *l, const void *data, int way)   //增加
{
	node_t *new;	
	node_t *p;

	new = malloc(sizeof(node_t));
	if (NULL == new)
		return -1;
	new->data = malloc(l->size);
	if (NULL == new->data) {
		free(new);
		return -1;
	}
	memcpy(new->data, data, l->size);
	if (way == HEADINSERT) {
		new->next = l->next;
		l->next = new;
	} else if (way == TAILINSERT) {
		for (p = l->next; p->next != NULL; p = p->next)	
			;
		p->next = new;
		new->next = NULL;
	}

	return 0;
}


int listDelete(listhead_t *l, const void *key, cmp_t cmp)   //删除
{
	node_t *p, *n;
	for(p = l->next;  p != NULL ; p = p->next  )
	{
		if(cmp(p->data, key) == 0)
		{
			n = p;
			l->next = p->next;
			free(n);
			return 1;
		}
		else if(cmp(p->next->data,key) == 0)
		{
			n = p->next;
			p->next = n->next;
			free(n);
			return 1;
		}
	}
	return 0;
}
int listUpdate(const listhead_t *l,const void *data,cmp_t cmp, const void *newdata) //修改
{
	node_t *p;
	for(p = l->next; p != NULL ; p = p->next)
	{
		if(cmp(p->data,data ) == 0)
		{
			memcpy(p->data,(char *)newdata, l->size);
			return 1;

		}

	}
return 0;

}
void listTraval(const listhead_t *l, pri_t pri)    //遍历
{
	node_t *p;

	for (p = l->next; p != NULL; p = p->next) {
		pri(p->data);
	}
}

/*
static void nodeDestroy(node_t **p)    //递归释放
{
	if ((*p)->next == NULL) {
		free(*p);
		*p = NULL;
	}

	nodeDestroy(&(*p)->next);
}

void listDestroy(listhead_t *l)
{
	nodeDestroy(&l->next);	
	free(l);
}
*/

void listDestroy(listhead_t *l)   //销毁
{
	node_t *p, *n;

	for (p = l->next, n = p->next; ; n = n->next) {
		free(p);
		p = n;
		if (p == NULL)
			break;
	}

	free(l);
}














