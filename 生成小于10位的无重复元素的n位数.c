//����������n(n<10)λ�����֣�ÿλ������0-9�����޸ķ�Χ������
//(ǰ�����ֲ��ظ�!)��C(m,n)��������ϡ�
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//circulate ָѭ����<=n�ĵ�cλ����λ��������lengthΪ�û�ָ�����������ĳ��ȡ�
void print_permutation(int length,int*A,int circulate)
{
 int i=0;
 int n=0;
 int j=0;
 //getchar();
//��С��/����length��������
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
  for(i=0;i<10;i++)//�޸�10Ϊ���������Ըı��������ķ�Χ��
  {
  int ok=1;
  //printf("2222222222222222222222222222222\n");
  for(j=0;j<circulate;j++)
   if(A[j]==i)
    {
      ok=0;
    }
   if(A[j]!=i)//���֮ǰ��A[O]--A[i]���ֹ�����治������֡�
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
   printf("����������nλ�����֣�ÿλ������0-9����(ǰ�����ֲ��ظ�!)\n");
   printf("������n��ֵ:\n");
   scanf("%d",&length);
   fflush(stdin);
   int *A=malloc(length*sizeof(int));
   memset(A,-1,sizeof(A));
   print_permutation(length,A,0);
}
