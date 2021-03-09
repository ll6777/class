#ifndef __LIST_H
#define __LISH_H

enum {HEADINSERT, TAILINSERT};

//数据域
typedef struct node_st{
//	void *data; // 数据域首地址
	struct node_st *prove;
	struct node_st *next;
	char data[0];
}node_t;

// 头结点
typedef struct {
	node_t head;
	int size;
	int nmemb;
}listhead_t;

typedef int (*cmp_t)(const void *data, const void *key);

typedef void (*pri_t)(const void *data);

int listheadInit(int size , listhead_t **l);  //初始化

int listInsert(listhead_t *l , const void *data, int way);  //增加

void listTraval(const listhead_t *l ,pri_t pri);   //遍历

int listDelete(listhead_t *l, const void *key, cmp_t cmp);    /*删除*/

void *listSearch(const listhead_t *l, const void *key, cmp_t cmp);    /*查找*/

void *listFetch(listhead_t *l, const void *key, cmp_t cmp);   /*摘除:删掉指定结点的同事获得数据*/

int listIsEmpty(const listhead_t *l);   /*是否为空*/

void listDestroy(listhead_t *l);    /*销毁*/

#endif

