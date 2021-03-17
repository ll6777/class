#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  NAMESIZE   32

struct stu_st{   //数据域
	int id;
	char name[NAMESIZE];
};

struct node_st{
	struct stu_st data;
	struct node_st *left;  //左结点
	struct node_st *right; //右结点
};

//插入新结点
static int treeInsert(struct node_st **root,const struct stu_st *data)
{
	struct node_st *new;
	if(*root == NULL){
		new = malloc(sizeof(*new));
		if(new == NULL)
			return -1;
		memcpy(&new->data,data,sizeof(struct stu_st));
		new->left = new->right = NULL;
		*root = new;
		return 0;
	}
	if(data->id  <= (*root)->data.id)
		return treeInsert(&(*root)->left, data);
	else
		return treeInsert(&(*root)->right,data);
}

//中序遍历
static void treeMidTraval(const struct node_st *root)
{
	if(root == NULL)
		return ;
	treeMidTraval(root->left);
	printf("%d  %s\n",root->data.id,root->data.name);
	treeMidTraval(root->right);

}
//销毁二叉树 
static void treeDestroy(struct node_st **root)
{
	if(root ==NULL)
	{
		return ;  //非法
	}
	if(*root ==NULL)
	{
		return ;  //空树
	}
	treeDestroy(&(*root)->left);
	treeDestroy(&(*root)->right);
	printf("%d   %s 被销毁\n", (*root)->data.id,(*root)->data.name );
	free(*root);
	*root = NULL;
	return ;
}


static void draw(const struct node_st *root,int level)  //画出二叉树，传的是二叉树和所在层数 
{
	if(root == NULL)
		return ;
	draw(root->right, level+1);
	for(int i = 0; i < level ; i++)
		printf("        ");
	printf("%d  %s\n", root->data.id,root->data.name);
	draw(root->left,level+1);
}

static void treeDraw(const struct node_st *root) //画画
{
	draw(root ,0);
}
struct node_st * treeffff(struct node_st *root ,int n )  //查找被删除节点
{
	if(root)
	{
		if(root->data.id == n)
			return root;
		else if(root->data.id > n )
			return treeffff(root->left,n);
		else
			return treeffff(root->right,n);
	}


}

struct node_st * treefind(struct node_st *root,struct node_st  *child)  //查找父节点
{
	static struct node_st *parent = NULL;
	if(root)
	{
		if(root->right == child || root->left == child)
				parent = root;
		treefind(root->left,child);
		treefind(root->right,child);
	}
	return parent;
}

 void  treeDeletry(struct node_st **root ,struct node_st *key )  //删除
{
	struct node_st *t = *root;
	struct node_st *parent = treefind(t,key);

	if(root == NULL)
		return ;
	if(key->left == NULL && key->right ==  NULL) //删除的三叶子结点
	{
		if(*root == key)
		{
		free(t);
		*root = NULL;
		return ;
		}
		if(parent->left == key)
			parent->left = NULL;
		else
			parent->right =NULL;
		free(key);
		return ;
	}
	else if(key->left != NULL && key->right == NULL) //要删除节点的左不为空 右为空
	{
		if(*root == key)
		{
			*root = key->left;
			free(key);
			return ;
		}
		if(parent->left == key)
			parent->left = key->left;
		else
			parent->right = key->left;
			free(key);
			return ;
	}
	else if(key->left == NULL && key->right != NULL) //要删除节点的左不为空 右为空
	{
		if(*root == key)
		{
			*root = key->right;
			free(key);
			return ;
		}
		if(parent->left == key)
			parent->left = key->right;
		else
			parent->right = key->right;
			free(key);
			return ;
	}
	
}

//统计节点个数
static void treetj(const struct node_st *root)
{	
	static int sum = 0 ;
	if(root == NULL)
		return ;
	treetj(root->left);
	printf("%d  %s  有 %d 个节点  \n",root->data.id,root->data.name, ++sum );
	treetj(root->right);
//	printf("有 %d 个节点 \n", sum);
}
static int treetttt(const struct node_st *root) //统计所有节点个数  老师
{
	if(root ==NULL)
		return 0;
	return 1 + treetttt(root->left) + treetttt(root->right);
}
static struct node_st *treeMaxNode(const struct node_st *root)// 找最大的节点
{
	if (root == NULL)
		return NULL;
	if (root->right == NULL)
		return (struct node_st *)root;
	return treeMaxNode(root->right);
}
static struct node_st *treeMinNode(const struct node_st *root) // 找小的
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL)
		return (struct node_st *)root;
	return treeMinNode(root->left);
}

static void treeTurnLeft(struct node_st **root) //左旋
{
	struct node_st *r,*cur;
	cur = *root;
	r = cur->right;

	*root = r;
	cur->right = NULL;
	treeMinNode(r)->left = cur;
}
static void treeTurnRight(struct node_st **root)  //右旋
{
	struct node_st *l, *cur;

	cur = *root;
	l = cur->left;

	*root = l;
	cur->left = NULL;
	treeMaxNode(l)->right = cur;
}
static void treeBalance(struct node_st **root)  // 平衡
{
	int val;
	if(*root == NULL)
		return ;
	while(1){
		val = treetttt((*root)->left) - treetttt((*root)->right);
		if(val > 1 ){
			treeTurnRight(root);
		}else if(val < 1){
			treeTurnLeft(root);
		}else
			break;
	}
	treeBalance(&(*root)->left);
	treeBalance(&(*root)->right);

}

int main(void)
{
	struct node_st *t;
	struct stu_st stu;
	int ids[] = {5,1,9,7,4,2,8,6,3};

	for(int i = 0 ; i< sizeof(ids) / sizeof(*ids) ; i++)
	{
		stu.id = ids[i];
		snprintf(stu.name, NAMESIZE, "stu%d", ids[i]);
		treeInsert(&t, &stu);
	}

	treeMidTraval(t);

	treeDraw(t);
	treeBalance(&t);
	int k = 6;
	struct node_st *key = treeffff(t,k);

	printf("删除了%d：\n", k);
	treeDeletry(&t,key);
	treeBalance(&t);
//	treeMidTraval(t);
	treeDraw(t);	
	treetj(t);
//	treeDestroy(&t);

	return 0;
}
































