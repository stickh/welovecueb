#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"malloc.h"
#define Max 20         //����������
typedef struct node{
    char data;
    struct node *lchild,*rchild;
}BinTNode;            //�Զ���������Ľ������
typedef BinTNode *BinTree;    //�����������ָ��
int NodeNum,leaf;            //NodeNumΪ�������leafΪҶ����
//==========������������㷨����������==============
//=====Ҫ�������������У����м�������"#"��ʾ��ָ���λ��==========
BinTree CreatBinTree(void)
{
    BinTree T;
    char ch;
    if((ch=getchar())=='#')
	return(NULL);       //����#�����ؿ�ָ��
    else{              
		T=(BinTree)malloc(sizeof(BinTNode));//���ɽ�� 
		T->data=ch;
	T->lchild=CreatBinTree();        //����������
		T->rchild=CreatBinTree();        //����������
	return(T);
    }
}
//========NLR �������=============
void Preorder(BinTree T)
{
    if(T) {
		printf("%c",T->data);    //���ʽ��
		Preorder(T->lchild);    //�������������
		Preorder(T->rchild);    //�������������
    }
}
//========LNR �������===============
 void Inorder(BinTree T)
{
    if(T) {
	Inorder(T->lchild);      //�������������
		printf("%c",T->data);    //���ʽ��
	Inorder(T->rchild);      //�������������
    }
}
//==========LRN �������============
void Postorder(BinTree T)
{
    if(T) {
	Postorder(T->lchild);    //�������������
		Postorder(T->rchild);    //�������������
	printf("%c",T->data);    //���ʽ��
    }
}
//=====���ú�����������������ȡ��������Ҷ�����ĵݹ��㷨========
int TreeDepth(BinTree T)
{
    int hl,hr,max;
    if(T){
	hl=TreeDepth(T->lchild);   	//�������
		hr=TreeDepth(T->rchild);    //�������
	max=hl>hr? hl:hr;           //ȡ������ȵ����ֵ
		NodeNum=NodeNum+1;         //������
	if(hl==0&&hr==0) leaf=leaf+1;  //���������Ϊ0����ΪҶ�ӡ�
		return(max+1);
    }
    else return(0);
}
//====����"�Ƚ��ȳ�"��FIFO�����У�����α���������==========
void Levelorder(BinTree T)
{
    int front=0,rear=1;
    BinTNode *cq[Max],*p;   //�������ָ������cq
    cq[1]=T;                //�����
    while(front!=rear)      
    {
		front=(front+1)%NodeNum;
		p=cq[front];            //����
		printf("%c",p->data);     //���ӣ��������ֵ 
		if(p->lchild!=NULL){
	    rear=(rear+1)%NodeNum;
		    cq[rear]=p->lchild;     //���������
		}
		if(p->rchild!=NULL){
	    rear=(rear+1)%NodeNum;
		    cq[rear]=p->rchild;     //���������
	}
    }
}
//==========������=================
void main()
{
    BinTree root;
    int i,depth;
    printf("\n");
printf("Creat Bin_Tree�� Input preorder:"); //������ȫ���������������У�
                         // ��#�������㣬��ABD###CE##F##
    root=CreatBinTree();       //���������������ظ����
    do {                    //�Ӳ˵���ѡ�������ʽ��������š�
		printf("\t********** select ************\n");
	printf("\t1: Preorder Traversal\n");    
		printf("\t2: Iorder Traversal\n");
	printf("\t3: Postorder traversal\n");
		printf("\t4: PostTreeDepth,Node number,Leaf number\n");
	printf("\t5: Level Depth\n"); //����α���֮ǰ����ѡ��4����������Ľ������
	printf("\t0: Exit\n");
		printf("\t*******************************\n");
	scanf("%d",&i);    //����˵���ţ�0-5��
	switch (i){
			case 1: printf("Print Bin_tree Preorder: ");
		Preorder(root);      //�������
				break;
	case 2: printf("Print Bin_Tree Inorder: ");
				Inorder(root);      //�������
		break;
		case 3: printf("Print Bin_Tree Postorder: ");
				Postorder(root);    //�������
		break;
	case 4: depth=TreeDepth(root);     //��������ȼ�Ҷ����
			printf("BinTree Depth=%d  BinTree Node number=%d",depth,NodeNum);
				printf("  BinTree Leaf number=%d",leaf);
			break;
			case 5: printf("LevePrint Bin_Tree: ");
		Levelorder(root);     //����α���
				break;
		default: exit(1);
	}
		printf("\n");
    } while(i!=0);
}  
