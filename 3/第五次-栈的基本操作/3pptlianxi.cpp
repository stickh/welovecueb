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

//������㷨��ȥ������������min��max֮�������Ԫ��
void Ex(slink *L, int min, int max)
{     slink *p, *q, *r;
q = L; p = L->next; //����L��ͷ���
while(p && p->data <= min) { 
   q = p; p = p->next;
}
while(p && p->data < max) {
  r = p; p = p->next; free(r);
}
q->next = p;
}

//������㷨��ȥ���㷨����ͬԪ��ֵ���㷨
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
k=getlen(head);
printf("������Ϊ��%d",k);
cout<<endl;
//Ex(head,5,10);
//printf("ɾ��min��max֮�������Ԫ�أ����յ������ɣ�");
//printlist(head);/*����������н���Ԫ��ֵ*/
Tp(head);
printf("ȥ����������ͬ����Ԫ�ص�ֵ�����յ������ɣ�");
printlist(head);/*����������н���Ԫ��ֵ*/
}

