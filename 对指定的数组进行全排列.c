//������ô���11111ʱǰ���ظ������޷������
//����11111��p[i]��11111�е��ظ�����c2
//������������xxx����p[i]���ظ�����c1
//�Ƚ�c1��c2�����c1<=c2,������ȷ��
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//circulate ָѭ����<=n�ĵ�cλ����λ��������lengthΪ�û�ָ�����������ĳ��ȡ�
void print_permutation(int length,int*A,int*P,int circulate)
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
  }
 else
  for(i=0;i<length;i++)//�޸�10Ϊ���������Ըı��������ķ�Χ��
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
   printf("����������nλ�����֣�ÿλ������0-9����(ǰ�����ֲ��ظ�!)\n");
   printf("������λ��:\n");
   scanf("%d",&length);
   fflush(stdin);
   int *P=malloc(length*sizeof(int));
   int *A=malloc(length*sizeof(int));
   for(i=0;i<length;i++)
   {
     printf("��%d��ֵ:\n",i);
     scanf("%d",&P[i]);
     fflush(stdin);
   }
   int j=0;
   int temp=0;
   //�������������С��������
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
