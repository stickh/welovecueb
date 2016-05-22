#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INITSIZE 10000
typedef struct 
{
char *base;
int top;
int stacksize;
}sqstack;

void InitStack(sqstack *S);
void Print(char expression[]);
void Choose(int choice,char expression[]);
void InputForm(char expression[]);
void JudgeForm(char expression[]);
int Match(char x,char y);
void Push(sqstack *S,char x);
void Pop(sqstack *S);

int main(void)
{

char expression[INITSIZE]={' '};
Print(expression);
while(true)
{
   printf("��enter������...");
   getchar();
   getchar();
   system("cls");
   Print(expression);
}
return 0;
}
void InitStack(sqstack *S)
{
S->top=-1;
S->base=(char *)malloc(INITSIZE*sizeof(char));
S->stacksize=INITSIZE;
}

void Print(char expression[])
{
int choice;
printf("Made By �׶�����ó�״�ѧ��ϢѧԺ\n");
printf("---------------------\n");
printf("ʹ��˵��:����������б�һ����ѧ���ʽ���������ŵ�����Ƿ�Ϸ�.\n");
printf("---------------------\n");
printf("1.����һ�������ŵ���ѧ���ʽ.\n");
printf("2.�жϵ�ǰ���ʽ�Ƿ�Ϸ�.\n");
printf("3.������������˳�.\n");
printf("---------------------\n");
printf("��ѡ����Ҫ�Ĳ���:");
scanf("%d",&choice);
Choose(choice,expression);
}
void Choose(int choice,char expression[])
{
switch(choice)
{
case 1:
   InputForm(expression);
   break;
case 2:
   JudgeForm(expression);
   break;
default:
   exit(0);
}
}
void InputForm(char expression[])
{
printf("������һ����ѧ���ʽ:\n");
scanf("%s",expression);
printf("����ɹ���\n");
}
void JudgeForm(char expression[])
{
printf("��ǰ���ʽ:");
printf("%s",expression);
sqstack p;
sqstack *S;
S=&p;
InitStack(S);
int flag=1;
int length;
int i;
length=strlen(expression);
for(i=0;i<length;i++)
{
   if(expression[i]=='('||expression[i]=='['||expression[i]=='{')
   {
    Push(S,expression[i]);
   }
   else if(expression[i]==')'||expression[i]==']'||expression[i]=='}')
   {
    if(Match(expression[i],S->base[S->top]))
    {
     Pop(S);
    }
    else
    {
     flag=0;
     break;
    }
   }
}
if(flag)
{
   printf("�Ϸ������ʽ�����ž�ƥ�䣡\n");
}
else
{
   printf("�Ƿ������ʽ�д��ڲ�ƥ�������\n");
}
}

int Match(char x,char y)
{
if(y=='('&&x==')')return true;
else if(y=='['&&x==']')return true;
else if(y=='{'&&x=='}')return true;
else return false;
}
void Push(sqstack *S,char x)
{
S->top++;
S->base[S->top]=x;
}
void Pop(sqstack *S)
{
S->top--;
}
