/*几种表示数结构的方法，如双亲表示法，孩子表示法等以及二叉树的前,中,后序遍历*/
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE_TREE 100
#define OVERFLOW -1
#define OK 1
#define ERROR 0

typedef char Elemtype;
typedef char TElemtype;
typedef int Status;

//*********************
//【双亲】表示法
//*********************
typedef struct PTNode{   //节点的结构

	Elemtype data;      //节点的数据
	int parent;         //双亲的位置
}PTNode;
typedef struct{         //树的节点  

	PTNode nodes[MAX_SIZE_TREE];
	int r, n;           //根节点的位置和节点数
}PTree;      


//*********************
//【孩子】表示法
//*********************

typedef struct CTNode{         //孩子节点结构

	int child;                 //孩子节点的下标
	struct CTNode *next;       //指向下一个孩子节点的指针

}*ChildPtr;
typedef struct{                //表头节点

	Elemtype data;             //节点的数据
	ChildPtr firstChild;       //第一个孩子节点的头结点指针
}CTBox;
typedef struct{                //树结构

	CTBox nodes[MAX_SIZE_TREE];//节点的数组
	int r, n;                  //根节点位置和节点数目
}ChildTree;

//*********************
//【孩子兄弟】表示法
//*********************
typedef struct CSNode{

	Elemtype data;
	struct CSNode *leftchild, *rightcib;
}CSNode, *CSTree;

//*********************
//【二叉树链表】表示法
//*********************
typedef struct BiTNode{

	Elemtype data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//递归构建二叉树
Status createBiTree(BiTree &T){
	TElemtype ch;
	printf("请输入节点的值,以字母进行输入,#表示空!");
	scanf_s("%c", &ch);
	getchar();    //用来吸收空格
	if (ch == '#'){
		T = NULL;
	}
	else{
		T = (BiTree)malloc(sizeof(BiTree));     //分配一个树节点的空间
		if (!T){
			printf("分配节点失败!");
			return OVERFLOW;
		}
		else{
			T->data = ch;
			printf("节点创建成功,该节点的值为%c\n", T->data);
			createBiTree(T->lchild);     //递归创建左子树
			createBiTree(T->rchild);     //递归创建右子树
			return OK;
		}
	}
}

//前序遍历函数
void PreOrderTraverse(BiTree T){
	if (T == NULL)
		return;      //空节点返回就行了
	else{
	
		printf("%c", T->data);          //打印节点的数据
		PreOrderTraverse(T->lchild);    //递归访问左子树
		PreOrderTraverse(T->rchild);    //递归访问右子树
	}
	printf("\n");
}

int main(){
	
	BiTree T = NULL;
	createBiTree(T);
	printf("前序遍历的结果为:");
	PreOrderTraverse(T);
	return OK;
}