/*���ֱ�ʾ���ṹ�ķ�������˫�ױ�ʾ�������ӱ�ʾ�����Լ���������ǰ,��,�������*/
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
//��˫�ס���ʾ��
//*********************
typedef struct PTNode{   //�ڵ�Ľṹ

	Elemtype data;      //�ڵ������
	int parent;         //˫�׵�λ��
}PTNode;
typedef struct{         //���Ľڵ�  

	PTNode nodes[MAX_SIZE_TREE];
	int r, n;           //���ڵ��λ�úͽڵ���
}PTree;      


//*********************
//�����ӡ���ʾ��
//*********************

typedef struct CTNode{         //���ӽڵ�ṹ

	int child;                 //���ӽڵ���±�
	struct CTNode *next;       //ָ����һ�����ӽڵ��ָ��

}*ChildPtr;
typedef struct{                //��ͷ�ڵ�

	Elemtype data;             //�ڵ������
	ChildPtr firstChild;       //��һ�����ӽڵ��ͷ���ָ��
}CTBox;
typedef struct{                //���ṹ

	CTBox nodes[MAX_SIZE_TREE];//�ڵ������
	int r, n;                  //���ڵ�λ�úͽڵ���Ŀ
}ChildTree;

//*********************
//�������ֵܡ���ʾ��
//*********************
typedef struct CSNode{

	Elemtype data;
	struct CSNode *leftchild, *rightcib;
}CSNode, *CSTree;

//*********************
//��������������ʾ��
//*********************
typedef struct BiTNode{

	Elemtype data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//�ݹ鹹��������
Status createBiTree(BiTree &T){
	TElemtype ch;
	printf("������ڵ��ֵ,����ĸ��������,#��ʾ��!");
	scanf_s("%c", &ch);
	getchar();    //�������տո�
	if (ch == '#'){
		T = NULL;
	}
	else{
		T = (BiTree)malloc(sizeof(BiTree));     //����һ�����ڵ�Ŀռ�
		if (!T){
			printf("����ڵ�ʧ��!");
			return OVERFLOW;
		}
		else{
			T->data = ch;
			printf("�ڵ㴴���ɹ�,�ýڵ��ֵΪ%c\n", T->data);
			createBiTree(T->lchild);     //�ݹ鴴��������
			createBiTree(T->rchild);     //�ݹ鴴��������
			return OK;
		}
	}
}

//ǰ���������
void PreOrderTraverse(BiTree T){
	if (T == NULL)
		return;      //�սڵ㷵�ؾ�����
	else{
	
		printf("%c", T->data);          //��ӡ�ڵ������
		PreOrderTraverse(T->lchild);    //�ݹ����������
		PreOrderTraverse(T->rchild);    //�ݹ����������
	}
	printf("\n");
}

int main(){
	
	BiTree T = NULL;
	createBiTree(T);
	printf("ǰ������Ľ��Ϊ:");
	PreOrderTraverse(T);
	return OK;
}