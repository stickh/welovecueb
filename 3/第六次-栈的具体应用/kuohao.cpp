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
   printf("按enter键继续...");
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
printf("Made By 首都经济贸易大学信息学院\n");
printf("---------------------\n");
printf("使用说明:本程序可以判别一个数学表达式中所有括号的配对是否合法.\n");
printf("---------------------\n");
printf("1.输入一个带括号的数学表达式.\n");
printf("2.判断当前表达式是否合法.\n");
printf("3.按其它任意键退出.\n");
printf("---------------------\n");
printf("请选择你要的操作:");
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
printf("请输入一个数学表达式:\n");
scanf("%s",expression);
printf("输入成功！\n");
}
void JudgeForm(char expression[])
{
printf("当前表达式:");
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
   printf("合法！表达式中括号均匹配！\n");
}
else
{
   printf("非法！表达式中存在不匹配的括号\n");
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
