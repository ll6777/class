#ifndef __LLIST_H
#define __LLIST_H

enum {INSERTHEAD, INSERTTAIL};

// 数据结点
struct node_st {
	void *data; // 数据域地址
	struct node_st *prev; // 前驱
	struct node_st *next; // 后继
};

// 头结点
typedef struct {
	struct node_st node;
	int nmemb;
	int size;
}llisthead_t;

typedef void (*pri_t)(const void *);
typedef int (*cmp_t)(const void *data, const void *key);

// 头结点的初始化
int llisthead_init(int size, llisthead_t **list);

/*插入*/
int llistInsert(llisthead_t *list, const void *data, int way);

/*遍历*/
void llistTraval(const llisthead_t *list, pri_t pri);

/*删除*/
int llistDelete(llisthead_t *list, const void *key, cmp_t cmp);

/*查找*/
void *llistSearch(const llisthead_t *list, const void *key, cmp_t cmp);

/*摘除:删掉指定结点的同事获得数据*/
int llistFetch(llisthead_t *list, const void *key, cmp_t cmp, void *data);

/*是否为空*/
int llistIsEmpty(const llisthead_t *list);

/*销毁*/
void listDestroy(llisthead_t *list);

#endif

