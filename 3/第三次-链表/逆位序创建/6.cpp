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
       	printf("������ÿ������Ԫ�ص�ֵ");
	for (i=n; i>0; --i)
	{p=(LinkList)malloc(sizeof(LNode));	
	scanf("%d", &(p->data));       
	p->next=L->next;
         L->next=p;/*���뵽ͷ���֮��*/
	}
		return L;}
void insert(LinkList L, int i,int e)
/*�ڵ�����L�ĵ�i��Ԫ��ǰ��������Ԫ��e*/	
{LinkList p,s;int j;
	p=L;j=0;
	while(p&&j<i-1)
        {p=p->next;j++;}
        if(!p||i<1) {printf("iֵ���Ϸ�");return;}
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
        if(!p->next||i<1) {printf("iֵ���Ϸ�");return 0;}
	q=p->next;
        p->next = q->next;
        *e=q->data;
        free(q);	
	return 1;}
void output(LinkList L)
/*����������н���Ԫ��ֵ*/
{	LinkList p;
	p=L->next;
	while (p )
		{printf("%d ",p->data);
		p=p->next;
		}
}
void main()
{	LinkList head;int n, x;int i,j;
   	printf("������Ԫ�ظ���");
	scanf("%d",&n);
	head=create(n);/* ������n��Ԫ�ؽ��ĵ�����*/
    printf("\n");
	output(head);/*����output����������������н���Ԫ��ֵ*/
    printf("\n");
	printf("��������������Ԫ�ص�ֵ");
	scanf("%d",&x);
	printf("������Ҫ���ĸ�λ��֮ǰ����");
	scanf("%d",&i);
    insert(head, i,x);/*�ڵ������i��Ԫ��ǰ����x*/
    printf("\n");
	output(head);/*����������н���Ԫ��ֵ*/
	printf("������Ҫɾ����λ��");
	scanf("%d",&i);
    j=Delete(head,i, &x);
    printf("\n");
    if(j)printf("%d",x);/*ɾ���ɹ�,�������ɾ������Ԫ��ֵ*/
    printf("\n"); 
    printf("���յ������ɣ�");
	output(head);/*����������н���Ԫ��ֵ*/
	
}
