#include <stdio.h> 
#include<stdlib.h>

#include <malloc.h> 

typedef enum{Link,Thread} PointerTag;  /*ָ���־*/ 

typedef char DataType; 

typedef struct BiThreTree{               /*������Ԫ��*/ 

        PointerTag LTag,RTag; 

        DataType data; 

        struct BiThreTree *lchild,*rchild; 

        }BiThreTree; 

BiThreTree *pre;                   /*ȫ�ֱ��������ڶ�������������*/ 

BiThreTree *CreateTree()            /*��ǰ�����뽨��������*/ 

{ 

        BiThreTree *T; 

        DataType ch; 

        scanf("%c",&ch); 

        if(ch=='#') 

           T=NULL; 

        else 

           {T=(BiThreTree *)malloc(sizeof(BiThreTree)); 

            T->data=ch; 

            T->LTag=Link;          /*��ʼ��ʱָ���־��ΪLink*/ 

            T->RTag=Link; 

            T->lchild=CreateTree(); 

            T->rchild=CreateTree(); 

           } 

        return T; 

} 

void InThread(BiThreTree *T) 

{ 

     BiThreTree *p; 

     p=T; 

     if(p) 

    { 

     InThread(p->lchild); 

     if(!p->lchild) 

        { p->LTag=Thread; 

          p->lchild=pre; 

        } 

     if(!pre->rchild) 

        { pre->RTag=Thread; 

          pre->rchild=p; 

        } 

     pre=p; 

     InThread(p->rchild); 

    } 

} 

BiThreTree *InOrderThrTree(BiThreTree *T) /*����������������*/ 

{ 

     BiThreTree *Thre;                 /*ThreΪͷ����ָ��*/ 

     Thre=(BiThreTree *)malloc(sizeof(BiThreTree)); 

     Thre->lchild=T; 

     Thre->rchild=Thre; 

     pre=Thre; 

     InThread(T); 

     pre->RTag=Thread; 

     pre->rchild=Thre; 

     Thre->rchild=pre; 

     return Thre; 

} 

void InThrTravel(BiThreTree *Thre)    /*�������������*/ 

{ 

     BiThreTree *p; 

     p=Thre->lchild; 

     while(p!=Thre)                  /*ָ���ָ��ͷ���ʱ����*/ 

     { 

       while(p->LTag==Link) 

          p=p->lchild; 

       printf("%4c",p->data); 

       while(p->RTag==Thread&&p->rchild!=Thre) 

         {p=p->rchild; 

          printf("%4c",p->data); 

         } 

       p=p->rchild; 

     } 

} 

void  main() 

{ 

    BiThreTree *T,*Thre; 

    printf("PreOrder Create Binary Tree:\n");

    T=CreateTree(); 

    Thre=InOrderThrTree(T); 

    printf("InOrder Traverse Binary Tree:\n");

    InThrTravel(Thre); 

    system("pause"); 

}

