#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<iostream.h> 
#define LIST_INIT_SIZE 50 
#define LISTINCREMENT 10 
#define TRUE 1 
#define FALSE 0 
#define OK 1 
#define ERROR 0 
#define CANCEL 0 
typedef struct{ 
int *elem; 
int length; 
int listsize; 
}sqlist; 
int compare(int X,int Y) 
{if(X==Y) 
return X; 
else return FALSE; 
}//compare的关系判断 
void visit(int &y) 
{ 
y=2*y; 
cout<<y<<" "; 
}//将y值增加为原来的2倍 
int initlist(sqlist &L) 
{ 
L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int)); 
if(!L.elem) 
return ERROR; 
else 
L.length=0; 
L.listsize=LIST_INIT_SIZE; 
return OK; 
}//构造一个空的线性表L 
int destroylist(sqlist &L) 
{ 
free(L.elem); 
return OK; 
}//销毁线性表L 
int clearlist(sqlist &L) 
{ 
L.length=0; 
return OK; 
}//将L重置为空表 
int listempty(sqlist L) 
{ 
if (0==L.length) 
return TRUE; 
else 
return FALSE; 
}//求当前表L是否为空 
int listlength(sqlist L) 
{ 
return L.length; 
}//求当前线性表L的长度 
int getelem(sqlist L,int i,int &e) 
{ 
if(i<1||i>L.length) 
exit(ERROR); 
e=*(L.elem+i-1); 
return OK; 
}//用e返回L中第i个数据元素的值 
int locateelem(sqlist L,int e,int(*compare)(int x1,int x2)) 
{ 
int i=1,j=0,*p; 
p=L.elem; 
while(i<=L.length&&!j) 
{ 
j=compare(*p++,e); 
++i; 
} 
if(i<=L.length) 
return i-1; 
else 
return FALSE; 
}//求L中第一个与e满足关系compare()的数据元素的位序，若不存在则返回0 
int priorelem(sqlist L,int cur_e,int &pre_e) 
{ 
int i=2,*p; 
p=L.elem+1; 
while(i<=L.length&&(*p++)!=cur_e) 
i++; 
if (i>L.length) 
return FALSE; 
else 
{ 
p=p-2;
pre_e=*p; 
return OK; 
} 
}//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义 
int nextelem(sqlist L,int cur_e,int &next_e) 
{ 
int i=1,*p; 
p=L.elem; 
while(i<L.length&&(*p++)!=cur_e) 
i++; 
if (i>=L.length) 
return FALSE; 
else 
{ 
next_e=*p; 
return OK; 
} 
}//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义 
int listinsert(sqlist &L,int i,int e) 
{ 
int *newbase,*p,*q; 
if((i<1)||(i>L.length+1)) 
return ERROR; 
if (L.length>=L.listsize) 
{ 
newbase=(int *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int)); 
if(!newbase) 
{ 
exit(0); 
} 
L.elem=newbase; 
L.listsize=L.listsize+LISTINCREMENT; 
} 
q=L.elem+i-1; 
for(p=L.elem+L.length-1;p>=q;--p) 
*(p+1)=*p; 
*q=e; 
++L.length; 
return OK; 
}//在线性表L中第i个位置插入元素e 
int listdelete(sqlist &L,int i,int &e) 
{ 
int *p,*q; 
if(i<1||i>L.length) 
return ERROR; 
else 
{ 
p=L.elem+i-1; 
e=*p; 
q=L.elem+L.length-1; 
for(++p;p<=q;++p) 
{ 
*(p-1)=*p; 

} 
L.length--; 
return OK; 
} 
}//将线性表中的第i个元素删除并返回其值 
int listtraverse(sqlist L,void(*visit)(int &p)) 
{ 
int i=1,*p; 
p=L.elem; 
while(i<=L.length) 
{ 
visit(*p); 
p++; 
i++; 
} 
return OK; 
}//依次对L中的每一个元素调用函数visit(),一旦visit()失败，则操作失败 

void move(sqlist &L)
{int i=0,j=L.length-1;
int temp;
while(i<j)
{while(i<j&&L.elem[i]%2!=0) i++;
while(i<j&&L.elem[j]%2==0) j--;
if(i<j)
{temp=L.elem[i];
L.elem[i]=L.elem[j];
L.elem[j]=temp;
}
}
}//把该表中所有奇数排在偶数之前,即表的前面为奇数,后面为偶数。

void main() 
{sqlist L; 
int i,j,k,b,n,e,m,a,cur_e,pre_e,next_e,s; 
initlist(L); 
cout<<"初始化后的基值地址:"<<L.elem<<" L.length=:"<<L.length<<" L.listsize=:"<<L.listsize<<endl; 
cout<<"新建一顺序表."<<endl; 
cout<<"当前表是否为空表"<<listempty(L)<<endl; 
cout<<"定义该线性表长度:"<<endl; 
cin>>a; 
cout<<"分别输入线性表的各个元素,按ENTER"<<endl; 
for(k=1;k<=a;k++){ 
cin>>j; 
i=listinsert(L,k,j);} 
for(b=1;b<=a;b++) 
cout<<L.elem[b-1]<<endl; 
listlength(L); 
cout<<"当前表长:"<<L.length<<endl; 
cout<<"输入要取的数的位置n(n<=a)"<<endl; 
cin>>n; 
getelem(L,n,e); 
//cout<<L.elem[n-1]<<endl; 
cout<<e<<endl;
cout<<"与该数相等的的一个数的位序为:"<<locateelem(L,e,compare)<<endl; 
cout<<"输入要取前驱的数的位置m(<=a)"<<endl; 
cin>>m; 
getelem(L,m,cur_e); 
if(priorelem(L,cur_e,pre_e)) 
cout<<"cur_e的前驱为:"<<pre_e<<endl; 
else 
cout<<"该元素没前驱"<<endl; 
nextelem(L,cur_e,next_e); 
if(nextelem(L,cur_e,next_e)) 
cout<<"cur_e的后继为:"<<next_e<<endl; 
else 
cout<<"该元素没后继"<<endl;
cout<<"奇数在前，偶数在后，并输出"<<endl; 

move(L);
for(s=1;s<=a;s++) 
cout<<L.elem[s-1]<<endl; 

cout<<"输入要删元素的位序m(<=a)"<<endl; 
cin>>m; 
listdelete(L,m,e); 
cout<<"被删的元素为:"<<e<<endl; 
cout<<"删除元素后表长为"<<L.length<<endl; 
//listtraverse(L,visit); 

cout<<"置为空表"<<clearlist(L)<<endl; 
cout<<"销毁线性表"<<destroylist(L)<<endl;
}