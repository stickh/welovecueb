#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100


 typedef struct TreeNode
{
   char data;
    TreeNode *lchild,*rchild;
}TreeNode;

void CreateBiTree(TreeNode *&,char []);    //���ַ�������
void preorder(TreeNode *&);                //�������ݹ����,ǰ��
void inorder(TreeNode *&);                 //�������ݹ����,����
void postorder(TreeNode *&);               //�������ݹ����,����
int count(TreeNode *&);                    //Ҷ�Ӽ��� 
int TreeHigh(TreeNode *&);                 //�ݹ������� 
void Exchange(TreeNode *&);                //������������������ 
void CopyTree(TreeNode *&,TreeNode *&);   //����������
void ReadyStack(void);                      //ջ��ʵ���� 
void  preorder1(TreeNode *);               //�ǵݹ��ǰ�����(����ջʵ��)
void  inorder1(TreeNode *);                //�ǵݹ���������(����ջʵ��)
void postorder1(TreeNode *);               //�ǵݹ�ĺ������(����ջʵ��)
void set(TreeNode *&,char [],char [],int,int,int,int);//����ǰ�������������У��õݹ鷽������ 

int main(void)
{
   char *s;
   s="ABC**DE*G**F***";
//   cout<<"������������б��������������п���*�Ŵ���:"; 
//   cin>>s;
   TreeNode *tree;
   cout<<"��ǰ���ַ������С�"<<s<<" ����......"<<endl; 
   CreateBiTree(tree,s);
   cout<<endl<<"�������ݹ����,ǰ��:";   preorder(tree);
   cout<<endl<<"�������ݹ����,����:";   inorder(tree);  
   cout<<endl<<"�������ݹ����,����:";   postorder(tree);
   cout<<endl<<endl<<"Ҷ����:"<<count(tree)<<endl;
   cout<<endl<<"����:"<<TreeHigh(tree)<<endl; 
   TreeNode *ctree;
   CopyTree(ctree,tree);
   cout<<endl<<"���ƶ�����."; 
   cout<<endl<<"�������ǵݹ����,ǰ��:";   preorder1(ctree);
   cout<<endl<<"�������ǵݹ����,����:";   inorder1(ctree);
   cout<<endl<<"�������ǵݹ����,����:";   postorder1(ctree);
   cout<<endl;
   Exchange(ctree);
   cout<<endl<<"������������������,ǰ��:";   preorder(ctree);
   cout<<endl<<"������������������,����:";   inorder1(ctree);
   cout<<endl<<endl<<endl<<"���У�";
   char pre[]="ABCDEGF"; 					 //ǰ�����������
   char in[]="CBEGDFA"; 						 //�������������
    cout<<"ǰ���������:"<<pre<<"    ";
    cout<<"�����������:"<<in<<endl;
    TreeNode *top;
    set(top,pre,in,0,strlen(pre)-1,0,strlen(in)-1); 		 //�õݹ鷽���ؽ�������
   cout<<"�ؽ�������,����������:";   postorder1(top);
   cout<<endl;
   system("PAUSE");	
   return 0;
}


void CreateBiTree(TreeNode *&p,char ar[]) 		  //���� 
{  char ch;
   static int i;
   ch=ar[i++];
   if(ch!='*')
   {   p=new TreeNode;
       p->data=ch;
       CreateBiTree(p->lchild,ar);
       CreateBiTree (p->rchild,ar);
   }
   else p=NULL;
}

void preorder(TreeNode *&p)      		 //�������ݹ����,ǰ��
{
   if(p)
   {   cout<<p->data;
       preorder(p->lchild);
       preorder(p->rchild);
   }
}

void inorder(TreeNode *&p)     		  //�������ݹ����,����
{
   if(p)
   {   inorder (p->lchild);
       cout<<p->data;
       inorder (p->rchild);
   }
}

void postorder(TreeNode *&p)  			  //�������ݹ����,����
{
   if(p)
   {   postorder (p->lchild);
       postorder (p->rchild);
       cout<<p->data;
   }
}

int count(TreeNode *&p)          		    //Ҷ�Ӽ��� 
{
    int m,n;
    if(p)
    {   m=count(p->lchild);
        n=count(p->rchild);
 	    if(m+n==0) return 1;
   	    else return m+n;
    }
    else return 0;
}

int TreeHigh(TreeNode *&p)       		   //�ݹ������� 
{
    int h1,h2;
    if(p)
    {   h1=1+TreeHigh(p->lchild);
        h2=1+TreeHigh(p->rchild);
        return (h1>=h2?h1:h2);
    }
    else return 0;
}

void Exchange(TreeNode *&p)          	   //������������������ 
{   TreeNode *temp;
    if(p)
    {   Exchange(p->lchild);
        Exchange(p->rchild);
        temp=p->rchild;
        p->rchild=p->lchild;
        p->lchild=temp;
    }
}

void CopyTree(TreeNode *&t,TreeNode *&s)		//����������,Ŀ�Ķ�����t,Դ������s
{
    if(s!=NULL)
    {   t=new TreeNode;
        t->data=s->data;
        CopyTree(t->lchild,s->lchild);
        CopyTree(t->rchild,s->rchild);
    }
    else t=NULL;
}

TreeNode *stack[MAXSIZE];
int p;
void ReadyStack(void)                   	 //ջ��ʵ���� 
{   p=-1;
}

void push(TreeNode *x)
{   if(p==MAXSIZE-1){cout<<"����!"<<endl;exit(0);}
    else stack[++p]=x;
}

void pop(TreeNode *&y)
{   if(p==-1){cout<<"��ջ,����!"<<endl;exit(0);}
    else y=stack[p--];
}

void  preorder1(TreeNode *t)            		  //�ǵݹ��ǰ�����(����ջʵ��)
{   ReadyStack();
    TreeNode *temp=t;
    while(temp!=NULL||p!=-1)
    {   if(temp!=NULL)
        {   push(temp);
            cout<<temp->data;
            temp=temp->lchild;
        }
        else
        {   pop(temp);
            temp=temp->rchild;
        }
    }
}


void  inorder1(TreeNode *t)            		  //�ǵݹ���������(����ջʵ��)
{   ReadyStack();
    TreeNode *temp=t;
    while(temp!=NULL||p!=-1)
    {   if(temp!=NULL)
        {   push(temp);
            temp=temp->lchild;
        }
        else
        {   pop(temp);
            cout<<temp->data;
            temp=temp->rchild;
        }
    }
}

void postorder1(TreeNode *t)           		  //�ǵݹ�ĺ������(����ջʵ��)
{
    ReadyStack();
   	TreeNode *temp=t;
	while(temp!=NULL||p!=-1)
	{
		while(temp!=NULL) 		 //temp�ǿ����ջ,������������,����,������������
		{
		    push(temp);
			if(temp->lchild)
				temp=temp->lchild;
			else
				temp=temp->rchild;
		}
		pop(temp);						//��ջ�õ��Ľ�������Ҷ��,Ҳ���������������ĵ���֧���
		cout<<temp->data; 				 //���temp���ֵ
		while(p!=-1&&stack[p]->rchild==temp)
 //ѭ����������������������������,Ӧ��ջ������ý��(�������ǿ�)��ֵ
		{
			pop(temp);
			cout<<temp->data;
		}
		if(p!=-1)  						//Ϊ����������������,�޸�temp��ֵ 
			temp=stack[p]->rchild;
		else
			temp=NULL;
	}
}

                     					 //��ǰ�������������У����������� 
void set(TreeNode *&p,char pre[],char in[],int p1,int q1,int p2,int q2) 
{                   				 //p1,q1,p2,q2�ֱ�Ϊ����pre(ǰ��),in(����)�ı߽�
	p=new TreeNode;
	p->data=pre[p1]; 				 //���������,������ֵ
	int t=p2;
	while(in[t]!=pre[p1]) t++; 				 //�����������
	if(t==p2)                 			  //��������
		p->lchild=NULL;  
	else
		set(p->lchild,pre,in,p1+1,p1+t-p2,p2,t-1);  //�ݹ�
	if(t==q2)                 			  //��������
		p->rchild=NULL; 
	else 
		set(p->rchild,pre,in,p1+t-p2+1,q1,t+1,q2);  //�ݹ�
}
