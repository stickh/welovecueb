#define N 50
#include <ctype.h>
#include <string.h>
#include "stdio.h"
#include "stdlib.h"
typedef struct{
 int top;
 double array[N];
}NumStack;//Êý×ÖÕ»
typedef struct{
 int top;
 char array[N];
}OpStack;//²Ù×÷·ûÕ»
int Cint(char mychar){
 return (mychar-48);
}
void PushNum(NumStack *numstack,double num){
 numstack->top++;
 numstack->array[numstack->top-1]=num;
}
void PopNum(NumStack *numstack,double *num){
 *num=numstack->array[numstack->top-1];
 numstack->top--;
}
void PushOp(OpStack *opstack,char op){
 opstack->top++;
 opstack->array[opstack->top-1]=op;
}
void PopOp(OpStack *opstack,char *op){
 *op=opstack->array[opstack->top-1];
 opstack->top--;
}
double Calc(double a,double b,char c){
 double result;
 switch(c){
  case '+':result=a+b;break;
  case '-':result=a-b;break;
  case '*':result=a*b;break;
  case '/':result=a/b;break;
 }
 return result;
}
char Priority(char y,char x){
  char priority='<';
  switch(x){
   case '+':
   case '-':if(y=='(' || y=='#')priority='>';break;
   case '*':
   case '/':if(y=='(' || y=='#'|| y=='+' || y=='-')priority='>';break;
   case '(':priority='>';break;
   case ')':if(y=='(')priority='=';break;
   case '#':if(y=='#')priority='=';break;
   default:priority='E';
  }
  return priority;
}
void Process(NumStack *numstack,OpStack *opstack,char x){
 double a,b;char c;
 static double tempnum=0.00000000;static int len=10;static int dot=0,flags=0;
 if(isdigit(x) || x=='.'){
  if(x=='.')dot=1;
  else{
   if(dot==0)
    tempnum=tempnum*10+Cint(x);
   else{
    tempnum=tempnum+(double)Cint(x)/len;
    len*=10;
   }
  }
 }
 else{
  if(flags==0 && x!='('){PushNum(numstack,tempnum);tempnum=0.00000000;len=10;dot=0;}
  switch(Priority(opstack->array[opstack->top-1],x)){
   case '>':PushOp(opstack,x);flags=0;break;
   case '<':
     PopOp(opstack,&c);
     PopNum(numstack,&b);
     PopNum(numstack,&a);
     PushNum(numstack,Calc(a,b,c));flags=1;
     Process(numstack,opstack,x);break;
   case '=':PopOp(opstack,&c);flags=1;break;
   default:printf("Wrong Express!");
	   exit(0);
  }
 }
}
main(){
 NumStack numstack;OpStack opstack;char s[N];int i=0;
 numstack.top=0;opstack.top=0;
 PushOp(&opstack,'#');
 printf("\nEnter your expression and end it with #:");scanf("%s",s);
 for(i=0;i<strlen(s);i++)
 Process(&numstack,&opstack,s[i]);
 printf("The result is %f",numstack.array[numstack.top-1]);
       }
