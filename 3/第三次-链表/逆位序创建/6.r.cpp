#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
	}LNode,*LinkList;
LinkList create(int n)
{int i;
	LinkList L, p;
	L = (LinkList) malloc(sizeof(LNode));	L->next=NULL;
       	printf("请输入每个结点的元素的值");
	for (i=n; i>0; --i)
	{p=(LinkList)malloc(sizeof(LNode));	
	scanf("%d", &(p->data));       
	p->next=L->next;
         L->next=p;/*插入到头结点之后*/
	}
		return L;}
void insert(LinkList L, int i,int e)
/*在单链表L的第i个元素前插入数据元素e*/	
{LinkList p,s;int j;
	p=L;j=0;
	while(p&&j<i-1)
        {p=p->next;j++;}
        if(!p||i<1) {printf("i值不合法");return;}
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next = p->next;
	p->next = s;
	}
int Delete(LinkList L, int i,int *e)
	{LinkList p, q;
	int j;
	p=L;j=0;
	while(p->next&&j<i-1)
    
   {p=p->next;j++;}
        if(!p->next||i<1) {printf("i值不合法");return 0;}
	q=p->next;
        p->next = q->next;
        *e=q->data;
        free(q);	
	return 1;}
void output(LinkList L)
/*输出单链表中结点的元素值*/
{	LinkList p;
	p=L->next;
	while (p )
		{printf("%d ",p->data);
		p=p->next;
		}
}
void main()
{	LinkList head;int n, x;int i,j;
   	printf("请输入元素个数");
	scanf("%d",&n);
	head=create(n);/* 建立有n个元素结点的单链表*/
    printf("\n");
	output(head);/*调用output函数，输出单链表中结点的元素值*/
    printf("\n");
	printf("请输入插入的数据元素的值");
	scanf("%d",&x);
	printf("请输入要在哪个位序之前插入");
	scanf("%d",&i);
    insert(head, i,x);/*在单链表第i个元素前插入x*/
    printf("\n");
	output(head);/*输出单链表中结点的元素值*/
	printf("请输入要删除的位序");
	scanf("%d",&i);
    j=Delete(head,i, &x);
    printf("\n");
    if(j)printf("%d",x);/*删除成功,则输出被删除结点的元素值*/
    printf("\n"); 
    printf("最终的链表变成：");
	output(head);/*输出单链表中结点的元素值*/
	
}
