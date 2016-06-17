#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100


 typedef struct TreeNode
{
   char data;
    TreeNode *lchild,*rchild;
}TreeNode;

void CreateBiTree(TreeNode *&,char []);    //用字符串建树
void preorder(TreeNode *&);                //二叉树递归遍历,前序
void inorder(TreeNode *&);                 //二叉树递归遍历,中序
void postorder(TreeNode *&);               //二叉树递归遍历,后序
int count(TreeNode *&);                    //叶子计数 
int TreeHigh(TreeNode *&);                 //递归求树高 
void Exchange(TreeNode *&);                //二叉树左右子树交换 
void CopyTree(TreeNode *&,TreeNode *&);   //二叉树拷贝
void ReadyStack(void);                      //栈初实例化 
void  preorder1(TreeNode *);               //非递归的前序遍历(利用栈实现)
void  inorder1(TreeNode *);                //非递归的中序遍历(利用栈实现)
void postorder1(TreeNode *);               //非递归的后序遍历(利用栈实现)
void set(TreeNode *&,char [],char [],int,int,int,int);//根据前序和中序遍历序列，用递归方法建树 

int main(void)
{
   char *s;
   s="ABC**DE*G**F***";
//   cout<<"按先序遍历序列遍历二叉树，其中空用*号代替:"; 
//   cin>>s;
   TreeNode *tree;
   cout<<"用前序字符串序列　"<<s<<" 建树......"<<endl; 
   CreateBiTree(tree,s);
   cout<<endl<<"二叉树递归遍历,前序:";   preorder(tree);
   cout<<endl<<"二叉树递归遍历,中序:";   inorder(tree);  
   cout<<endl<<"二叉树递归遍历,后序:";   postorder(tree);
   cout<<endl<<endl<<"叶子数:"<<count(tree)<<endl;
   cout<<endl<<"树高:"<<TreeHigh(tree)<<endl; 
   TreeNode *ctree;
   CopyTree(ctree,tree);
   cout<<endl<<"复制二叉树."; 
   cout<<endl<<"二叉树非递归遍历,前序:";   preorder1(ctree);
   cout<<endl<<"二叉树非递归遍历,中序:";   inorder1(ctree);
   cout<<endl<<"二叉树非递归遍历,后序:";   postorder1(ctree);
   cout<<endl;
   Exchange(ctree);
   cout<<endl<<"二叉树左右子树交换,前序:";   preorder(ctree);
   cout<<endl<<"二叉树左右子树交换,中序:";   inorder1(ctree);
   cout<<endl<<endl<<endl<<"现有：";
   char pre[]="ABCDEGF"; 					 //前序遍历后数组
   char in[]="CBEGDFA"; 						 //中序遍历后数组
    cout<<"前序遍历数组:"<<pre<<"    ";
    cout<<"中序遍历数组:"<<in<<endl;
    TreeNode *top;
    set(top,pre,in,0,strlen(pre)-1,0,strlen(in)-1); 		 //用递归方法重建二叉树
   cout<<"重建二叉树,后序遍历结果:";   postorder1(top);
   cout<<endl;
   system("PAUSE");	
   return 0;
}


void CreateBiTree(TreeNode *&p,char ar[]) 		  //建树 
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

void preorder(TreeNode *&p)      		 //二叉树递归遍历,前序
{
   if(p)
   {   cout<<p->data;
       preorder(p->lchild);
       preorder(p->rchild);
   }
}

void inorder(TreeNode *&p)     		  //二叉树递归遍历,中序
{
   if(p)
   {   inorder (p->lchild);
       cout<<p->data;
       inorder (p->rchild);
   }
}

void postorder(TreeNode *&p)  			  //二叉树递归遍历,后序
{
   if(p)
   {   postorder (p->lchild);
       postorder (p->rchild);
       cout<<p->data;
   }
}

int count(TreeNode *&p)          		    //叶子计数 
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

int TreeHigh(TreeNode *&p)       		   //递归求树高 
{
    int h1,h2;
    if(p)
    {   h1=1+TreeHigh(p->lchild);
        h2=1+TreeHigh(p->rchild);
        return (h1>=h2?h1:h2);
    }
    else return 0;
}

void Exchange(TreeNode *&p)          	   //二叉树左右子树交换 
{   TreeNode *temp;
    if(p)
    {   Exchange(p->lchild);
        Exchange(p->rchild);
        temp=p->rchild;
        p->rchild=p->lchild;
        p->lchild=temp;
    }
}

void CopyTree(TreeNode *&t,TreeNode *&s)		//二叉树拷贝,目的二叉树t,源二叉树s
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
void ReadyStack(void)                   	 //栈初实例化 
{   p=-1;
}

void push(TreeNode *x)
{   if(p==MAXSIZE-1){cout<<"上溢!"<<endl;exit(0);}
    else stack[++p]=x;
}

void pop(TreeNode *&y)
{   if(p==-1){cout<<"出栈,下溢!"<<endl;exit(0);}
    else y=stack[p--];
}

void  preorder1(TreeNode *t)            		  //非递归的前序遍历(利用栈实现)
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


void  inorder1(TreeNode *t)            		  //非递归的中序遍历(利用栈实现)
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

void postorder1(TreeNode *t)           		  //非递归的后序遍历(利用栈实现)
{
    ReadyStack();
   	TreeNode *temp=t;
	while(temp!=NULL||p!=-1)
	{
		while(temp!=NULL) 		 //temp非空则进栈,向左子树深入,否则,向右子树深入
		{
		    push(temp);
			if(temp->lchild)
				temp=temp->lchild;
			else
				temp=temp->rchild;
		}
		pop(temp);						//退栈得到的结点可能是叶子,也可能是无右子树的单分支结点
		cout<<temp->data; 				 //输出temp点的值
		while(p!=-1&&stack[p]->rchild==temp)
 //循环条件成立则表明右子树访问完毕,应退栈并输出该结点(右子树非空)的值
		{
			pop(temp);
			cout<<temp->data;
		}
		if(p!=-1)  						//为向右子树继续遍历,修改temp的值 
			temp=stack[p]->rchild;
		else
			temp=NULL;
	}
}

                     					 //有前序和中序遍历序列，建立二叉树 
void set(TreeNode *&p,char pre[],char in[],int p1,int q1,int p2,int q2) 
{                   				 //p1,q1,p2,q2分别为数组pre(前序),in(中序)的边界
	p=new TreeNode;
	p->data=pre[p1]; 				 //建立根结点,输入数值
	int t=p2;
	while(in[t]!=pre[p1]) t++; 				 //中序数组后移
	if(t==p2)                 			  //无左子树
		p->lchild=NULL;  
	else
		set(p->lchild,pre,in,p1+1,p1+t-p2,p2,t-1);  //递归
	if(t==q2)                 			  //无右子树
		p->rchild=NULL; 
	else 
		set(p->rchild,pre,in,p1+t-p2+1,q1,t+1,q2);  //递归
}
