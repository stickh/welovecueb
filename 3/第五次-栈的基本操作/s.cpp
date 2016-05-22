#include "iostream.h"
//���ﻹҪ��������Ĭ�ϵĳ���ͷ�ļ�
//#include "head.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define TRUE 1 
#define FALSE 0 
#define OK 1 
#define OVERFLOW 0 
#define ERROR 0 
#define CANCEL 0 
typedef int SElemType;

typedef struct
{
  SElemType *base;
  SElemType *top;
  int stacksize;
}SqStack;

int InitStack(SqStack &S)
{
   S.base=new SElemType[STACK_INIT_SIZE];
   if(!S.base) return OVERFLOW;
   S.top=S.base;
   S.stacksize=STACK_INIT_SIZE;
   return OK;
}

int DestroyStack(SqStack &S)
{
  S.top=NULL;
  S.base=NULL;
  delete[] S.base;
  S.stacksize=0;
  return OK;
}

int StackEmpty(SqStack s)
{
  if(s.top==s.base) return 1;
      else          return 0;
}

int GetTop(SqStack &s,SElemType &e)
{
  if(s.top==s.base) return ERROR;
  e=*(s.top-1);
  return OK;
}

int StackLength(SqStack s)
{
  return s.top-s.base;
}

int ClearStack(SqStack &S)
{
   S.top=S.base;
   return OK;
}

int Push(SqStack &s,SElemType e)
{
  if(s.top-s.base>=s.stacksize)
   return OVERFLOW;
  *s.top++=e;
return OK;
}

int Pop(SqStack &s,SElemType &e)
{
  if(s.top==s.base) return ERROR;
  e=*--s.top;
 return OK;
}

int StackTraverse(SqStack s,int(*visit)(SElemType c))//���������ò�Ҫ�ã���Ϊ���Ѿ��ƻ���ջ������
{
  while(s.top>s.base)
   visit(*s.base++);
   cout<<endl;
   return OK;
}
int visit(SElemType c)
{
  cout<<c<<" ";
  return OK;
}
void main() //Ϊ����ת���ĺ��� 
{ 
SqStack S; 
SElemType N;
int M; 
SElemType e; 
InitStack(S); 
cout<<"input the number:"; 
cin>>N; 
cout<<"����Ҫת��������:"; 
cin>>M; 
while(N) 
{ 
Push(S,N%M); 
N=N/M; //ת��ΪM���Ƶ��� 
} 
while(!StackEmpty(S)) 
{ 
Pop(S,e); 
cout<<e; 
} 
cout<<endl;
}
