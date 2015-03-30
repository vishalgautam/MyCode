#include<stdlib.h>
#include<stdio.h>
main()
{
 int no,j,k,m=0,*a;
 int sum,give,take,row,col,total;
 while(1){
 sum=give=take=row=col=total=0;
 scanf("%d",&no);
 if(no==0) break;
 a=(int *)malloc(no*no*4);
 k=no*no;
        for(j=0;j<k;j++)
                scanf("%d",&a[j]);
 j=0;k=0;
 while(j<no)
   {
        col=j++;k=0;
        give=take=0;
        while(k++<no)
                {
                        give+=a[row++];
                        take+=a[col];
                        col+=no;
                }
 total+=give;
 if(give-take>0)
        sum+=(give-take);
 }
 printf("%d. %d %d\n",++m,total,sum);
}     
}
