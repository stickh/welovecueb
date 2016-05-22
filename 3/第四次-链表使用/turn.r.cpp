#include "stdio.h"
#include "stdlib.h"
typedef struct node
{  int data;
   struct node *next;
}slink;

slink *creslink(int n)
{
  slink *head,*p,*s;
  int i;
  if(n<1) return NULL;
  p=head=(slink *)malloc(sizeof(slink));
  printf("请输入每个结点的元素的值");
  for(i=1;i<=n;i++)
  { s=(slink *)malloc(sizeof(slink));
    scanf("%d",&(s->data));
	p->next=s;
	p=s;
  }
  p->next=NULL;
  return head;
}

int Delete(slink *head,int i, int *e)
{slink *p,*q;
int j;
if (i<1)return 0;
p=head;j=0;
while(p->next!=NULL && j<i-1)
{p=p->next;j++;}
if(p->next==NULL)return 0;
q=p->next;
p->next=q->next;
*e=q->data;
free(q);
return 1;
}


int insert(slink *head,int i, int x)
{slink *p,*q;
int j;
if (i<1)return 0;
p=head;j=0;
while(p!=NULL && j<i-1)
{p=p->next;j++;}
if(p==NULL)return 0;
q=(slink *)malloc(sizeof(slink));
q->data=x;
q->next=p->next;
p->next=q;
return 1;
}

void printlist(slink *head)
{slink *p;
 p=head->next;
 while(p!=NULL)
 {printf("%4d",p->data);
 p=p->next;
 }
 printf("\n");
}

void turn(slink *head)
{slink *p,*q;
p=head->next;head->next=NULL;
while(p!=NULL)
{
	q=p->next;
	p->next=head->next;
	head->next=p;
	p=q;
}
}//单链表的原地逆转；

void main()
{ slink *head;
int n,x,i,j;
printf("请输入元素个数");
scanf("%d",&n);
head=creslink(n);
printf("\n");
printlist(head);
printf("\n");
printf("请输入插入的数据元素的值");
scanf("%d",&x);
printf("请输入要在哪个位序之前插入");
scanf("%d",&i);
insert(head, i,x);/*在单链表第i个元素前插入x*/
printf("\n");
printlist(head);/*输出单链表中结点的元素值*/
printf("请输入删除的数据元素的位序");
scanf("%d",&i);
j=Delete(head,i, &x);
printf("\n");
if(j)printf("%d",x);/*删除成功,则输出被删除结点的元素值*/
printf("\n"); 
printf("最终的链表变成：");
printlist(head);/*输出单链表中结点的元素值*/
turn(head);
printf("原地逆转后的链表变成：");
printlist(head);/*输出单链表中结点的元素值*/
}


