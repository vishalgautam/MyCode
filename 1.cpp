#include<stdio.h>
#include<stdlib.h>
int is_not_prime[1000000]={0};
int main()
{
   int  a[1000000]={0},i,j,k,n,q1,q2,phi[1000000]={0},temp;   
   long double f,f1,f2;
   for(i=0;i<=999998;i++)
   {
      a[i]=i+2;
      phi[i+1]=i+1;
   }
   for(j=0;j<i;j++)
   {
	  temp=a[j];
      if(is_not_prime[temp]==0)
      {
      //   printf("%d\n ",a[j]);
      
         for(k=1;temp*k<1000000;k++)
         {
            n=temp*k;
      //      printf("%d ",n);
            f1=temp;
            f2=phi[n];
            f=(f2*((f1-1)/f1));
            phi[n]=f;
            is_not_prime[n]=1;
         }
      //   printf("\n");

   
         
      }
   }
   phi[1000000]=400000;
   scanf("%d",&q1);

   for(i=0;i<q1;i++)
   {
      scanf("%d",&q2);

           printf("%d\n",phi[q2]);}


return 0;
}
