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

void printlist(slink *head)
{slink *p;
 p=head->next;
 while(p!=NULL)
 {printf("%4d",p->data);
 p=p->next;
 }
 printf("\n");
}



void bring(slink *head1,slink *head2)
{
  slink *l,*p,*q;
  int i;
  l=head2->next;
  while(l!=NULL)
  { p=head1;q=head1->next;
    while(q!=NULL&&q->data!=l->data)
	{p=q;q=q->next;}
	if(q!=NULL)
	{p->next=q->next;
	  free(q);
	}
	l=l->next;
  }
  for(l=head1;l->next!=NULL;l=l->next);
  l->next=head2->next;
  free(head2);
}

void main()
{ slink *head1,*head2;
int n,x,i,j;
printf("请输入第一个链表元素的个数");
scanf("%d",&n);
head1=creslink(n);
printf("\n");
printlist(head1);
printf("请输入第二个链表元素的个数");
scanf("%d",&n);
head2=creslink(n);
printf("\n");
printlist(head2);
printf("\n");
printf("合并后的链表变成：");
bring(head1,head2);
printlist(head1);/*输出单链表中结点的元素值*/
}



