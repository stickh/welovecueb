#define MAXSIZE 50
#include "Stdio.h"
#define  X 10
#define  Y 10
typedef struct{
       int i,j;
       int e;
}Triple;
typedef struct
   { Triple data[MAXSIZE+1];
     int mu,nu,tu;
    }TSMatrix;
 int num[X],cpot[Y];

TSMatrix  createsmatrix()
    {
      TSMatrix M;
       int i,j,k=1,x,m,n;
        int a[X][Y];
   printf("请输入矩阵的行数mu:\n");
    scanf("%d",&m);
     printf("请输入矩阵的列数nu:\n");
    scanf("%d",&n);
  printf("请输入矩阵的各个元素:\n");
  for(i=0;i<m;i++)
  for(j=0;j<n;j++)
   scanf("%d",&a[i][j]);
       for(i=0;i<m;i++)
      { for(j=0;j<n;j++)
       { x=a[i][j];
          if(x)
        {M.data[k].i=i+1;
         M.data[k].j=j+1;
         M.data[k].e=x;
         k++;}
        } }
       M.mu=m;
       M.nu=n;
       M.tu=k-1;
     return(M);
    }

 TSMatrix   fasttransposesmatrix(TSMatrix M)
    {   TSMatrix T;
       int col,t,p,q;
         T.mu=M.nu;
         T.nu=M.mu;
         T.tu=M.tu;
        if(T.tu)
         {
           for(col=1;col<=M.nu;++col)
            num[col]=0;
            for(t=1;t<=M.tu;++t)
             ++num[M.data[t].j];
             cpot[1]=1;
             for(col=2;col<=M.nu;++col)
              cpot[col]=cpot[col-1]+num[col-1];
             for(p=1;p<=M.tu;++p)
              {
                 col=M.data[p].j;
                  q=cpot[col];
                 T.data[q].i=M.data[p].j;
                   T.data[q].j=M.data[p].i;
                 T.data[q].e=M.data[p].e;
                 ++cpot[col];
              }
          }
        return(T);
    }

 void   print(TSMatrix T)
        { int b[X][Y];
           int i,j,t,m=T.mu,n=T.nu;
          for(i=0;i<m;i++)
          for(j=0;j<n;j++)
           b[i][j]=0;
           for(t=1;t<=T.tu;t++)
            b[(T.data[t].i)-1][(T.data[t].j)-1]=T.data[t].e;
            printf("转置矩阵是:");
          for(i=0;i<m;i++)
          { printf("\n");
          for(j=0;j<n;j++)
          printf("%5d",b[i][j]);
           }  
         }

 void main()
{  int i,j;
    TSMatrix M,T;
   M=createsmatrix();
    T=fasttransposesmatrix(M);
    print(T);
   printf("\n");
  
}
