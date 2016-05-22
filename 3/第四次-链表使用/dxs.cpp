//以下程序为多项式求和的程序
#include"stdio.h"
#include"stdlib.h"
typedef struct node
{  int xc;
   int e;
   struct node *next;
}dxs;
dxs *creat(int m)
{dxs *head,*p,*q;int i;
p=head=(dxs *)malloc(sizeof(dxs));
for(i=1;i<=m;i++)
{q=(dxs *)malloc(sizeof(dxs));
scanf("%d%d",&q->xc,&q->e);
p->next=q;
p=q;
}
p->next=NULL;
return head;
}

plus(dxs *h1,dxs *h2)
{dxs *h,*p1,*p2,*q;
h=h1;
p1=h1->next;
p2=h2->next;
while(p1!=NULL&&p2!=NULL)
if(p1->e<p2->e)
{h->next=p1;h=p1;p1=p1->next;}
else if(p2->e<p1->e)
{h->next=p2;h=p2;p2=p2->next;} 
else if(p1->xc+p2->xc!=0)
{p1->xc=p1->xc+p2->xc;
h->next=p1;h=p1;p1=p1->next;
q=p2;
p2=p2->next;
free(q);
} 
else
{q=p1;p1=p1->next;free(q);
q=p2;p2=p2->next;free(q);
}
if(p1!=NULL)
  h->next=p1;
else h->next=p2;
free(h2);
}
void list(dxs *head)
{dxs *p=head->next;
while(p!=NULL)
{printf("(%4d,%4d) ",p->xc,p->e);
p=p->next;
}
printf("/n");
}
main()
{dxs *h1,*h2;
h1=creat(3);
h2=creat(4);
plus(h1,h2);
list(h1);
}