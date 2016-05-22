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

void main()
{ slink *head;
int n,x,i,j;
printf("������Ԫ�ظ���");
scanf("%d",&n);
head=creslink(n);
printf("\n");
printlist(head);
printf("\n");
printf("��������������Ԫ�ص�ֵ");
scanf("%d",&x);
printf("������Ҫ���ĸ�λ��֮ǰ����");
scanf("%d",&i);
insert(head, i,x);/*�ڵ������i��Ԫ��ǰ����x*/
printf("\n");
printlist(head);/*����������н���Ԫ��ֵ*/
printf("������ɾ��������Ԫ�ص�λ��");
scanf("%d",&i);
j=Delete(head,i, &x);
printf("\n");
if(j)printf("%d",x);/*ɾ���ɹ�,�������ɾ������Ԫ��ֵ*/
printf("\n"); 
printf("���յ������ɣ�");
printlist(head);/*����������н���Ԫ��ֵ*/
}


