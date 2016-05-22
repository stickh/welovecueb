#include "stdio.h"
#include "stdlib.h"
#include "iostream.h"
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

int getlen(slink *head)
{slink *p;
int n;
p=head->next;n=0;
while(p!=NULL)
{n++;p=p->next;}
return n;
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

//下面的算法是去掉有序链表中min和max之间的数据元素
void Ex(slink *L, int min, int max)
{     slink *p, *q, *r;
q = L; p = L->next; //链表L带头结点
while(p && p->data <= min) { 
   q = p; p = p->next;
}
while(p && p->data < max) {
  r = p; p = p->next; free(r);
}
q->next = p;
}

//下面的算法是去掉算法中相同元素值的算法
void Tp(slink *L)
{     slink *p, *q, *r;
for(p = L; p; p = p->next)  
for(q = p, r = q->next; r; r = q->next)  
  if (r->data != p->data)   q = r; 
else {
      q->next = r->next;  free(r);  
    }
}


void main()
{ slink *head;
int n,x,i,j,k;
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
k=getlen(head);
printf("链表长度为：%d",k);
cout<<endl;
//Ex(head,5,10);
//printf("删除min和max之间的数据元素，最终的链表变成：");
//printlist(head);/*输出单链表中结点的元素值*/
Tp(head);
printf("去掉链表中相同数据元素的值，最终的链表变成：");
printlist(head);/*输出单链表中结点的元素值*/
}

