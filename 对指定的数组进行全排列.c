//首先怎么解决11111时前后重复导致无法输出？
//计算11111中p[i]在11111中的重复次数c2
//计算生成数组xxx中数p[i]的重复次数c1
//比较c1，c2，如果c1<=c2,则结果正确。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//circulate 指循环中<=n的第c位的填位操作，而length为用户指定的生成数的长度。
void print_permutation(int length,int*A,int*P,int circulate)
{
 int i=0;
 int n=0;
 int j=0;
 //getchar();
//对小于/等于length进行讨论
  if(circulate==length)
  {
     // printf("*****************************\n");
      for(i=0;i<length;i++)
      {
          printf("%d",A[i]);
      }
      printf("\n");
  }
 else
  for(i=0;i<length;i++)//修改10为其他数可以改变生成数的范围。
  {
      int c1=0;
      int c2=0;
      if(i==0||(P[i]!=P[i-1]&&i!=0))
      {
         for(j=0;j<circulate;j++)
           {
               if(A[j]==P[i])
               {
                 c1++;
               }
           }
           for(j=0;j<length;j++)
           {
               if(P[j]==P[i])
               {
                   c2++;
               }
           }
           if(c1<c2)
           {
           A[circulate]=P[i];
           print_permutation(length,A,P,circulate+1);
           }
      }
  }
}
int main()
{
   int i=0;
   int length=0;
   printf("本程序生成n位的数字，每位包含从0-9的数(前后数字不重复!)\n");
   printf("请输入位数:\n");
   scanf("%d",&length);
   fflush(stdin);
   int *P=malloc(length*sizeof(int));
   int *A=malloc(length*sizeof(int));
   for(i=0;i<length;i++)
   {
     printf("第%d个值:\n",i);
     scanf("%d",&P[i]);
     fflush(stdin);
   }
   int j=0;
   int temp=0;
   //将输入的数组由小到大排序
   for(i=0;i<length-1;i++)
   {
       for(j=i;j<length;j++)
       {
           if(P[i]>P[i+1])
           {
              temp=P[i];
              P[i]=P[i+1];
              P[i+1]=temp;
           }
       }
   }
   for(i=0;i<length;i++)
   {
       printf("P[i]:%d\n",P[i]);
   }
   memset(A,-1,sizeof(A));
   print_permutation(length,A,P,0);
}
