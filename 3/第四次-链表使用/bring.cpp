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
  printf("������ÿ������Ԫ�ص�ֵ");
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
printf("�������һ������Ԫ�صĸ���");
scanf("%d",&n);
head1=creslink(n);
printf("\n");
printlist(head1);
printf("������ڶ�������Ԫ�صĸ���");
scanf("%d",&n);
head2=creslink(n);
printf("\n");
printlist(head2);
printf("\n");
printf("�ϲ���������ɣ�");
bring(head1,head2);
printlist(head1);/*����������н���Ԫ��ֵ*/
}



