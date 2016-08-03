//本程序生成n(n<10)位的数字，每位包含从0-9（可修改范围）的数
//(前后数字不重复!)即C(m,n)个数的组合。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//circulate 指循环中<=n的第c位的填位操作，而length为用户指定的生成数的长度。
void print_permutation(int length,int*A,int circulate)
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
    //  printf("111111111111111111111111111111111111\n");
  }

 else
  for(i=0;i<10;i++)//修改10为其他数可以改变生成数的范围。
  {
  int ok=1;
  //printf("2222222222222222222222222222222\n");
  for(j=0;j<circulate;j++)
   if(A[j]==i)
    {
      ok=0;
    }
   if(A[j]!=i)//如果之前在A[O]--A[i]出现过则后面不允许出现。
   {
       if(ok==1)
       {
           A[circulate]=i;
           print_permutation(length,A,circulate+1);
       }
   }
  }
}
int main()
{
   int length=0;
   printf("本程序生成n位的数字，每位包含从0-9的数(前后数字不重复!)\n");
   printf("请输入n的值:\n");
   scanf("%d",&length);
   fflush(stdin);
   int *A=malloc(length*sizeof(int));
   memset(A,-1,sizeof(A));
   print_permutation(length,A,0);
}
