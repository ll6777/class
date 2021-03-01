
//2.   增删查
#include <stdio.h>

#include <string.h>
#include <stdlib.h>

int findElm(int *a, int n, int key);
void addElm(int **a, int *n, int newelm);
int delElm(int **a, int *n, int delElm);
void showArr(int *a, int n);
int main(void)
{
	int *arr = NULL;
	int n = 0;
	int ret;

	for (int i = 1; i <= 10; i++) {
		addElm(&arr, &n, i);
	}

	showArr(arr, n);

	ret = findElm(arr, n, 3);
	if (ret == -1) {
		printf("没有要查找的元素\n");
	} else {
		printf("找到了:%d\n", ret);
	}

	delElm(&arr, &n, 5);
	showArr(arr, n);

	return 0;
}

// 增加
/*
 *a数组的首地址 a是存储数组首地址的指针变量的地址
 *n成员个数
 newelm要插入的新的元素
 */
void addElm(int **a, int *n, int newelm)
{
	*a = realloc(*a, (*n+1) * sizeof(int));
	if (*a == NULL)
		return ;
	(*a)[*n] = newelm;
	(*n)++;
}

/*
 删除指定元素
 */
int delElm(int **a, int *n, int delElm)
{
	int i;
	// 找到
	for (i = 0; i < *n; i++) {
		if ((*a)[i] == delElm) {
			memcpy(*a+i, *a+i+1, (*n-i-1) * sizeof(int));
			break;
		}
	}

	if (i == *n)
		return -1;
	(*n)--;
	*a = realloc(*a, *n*sizeof(int));
	return 0;
}

/*
 查找指定元素
 */
int findElm(int *a, int n, int key)
{
	int i;

	for(i = 0; i < n; i++) {
		if (a[i] == key)
			break;
	}
	if (i == n) {
		// 没有找到
		return -1;
	}

	// 找到了
	return a[i];
}

/*
 打印数组
 */
void showArr(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d\n", a[i]);
}




