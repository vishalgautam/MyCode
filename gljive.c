#include<math.h>
#include<stdio.h>
 int main(){
     int sum=0,n,t=9,x,y,b=1;
     scanf("%d",&n);
     sum+=n;
     while(t--){
         scanf("%d",&n);
         x=fabs(100-sum);
         y=fabs(100-(sum+n));
         if(x<y){
             b=0;
             printf("%d\n",sum);
             break;
         }
         else if(n&&x==y) {
             b=0;
            printf("%d\n",sum+n);
            break;
         }
         sum+=n;
     }
     if(b) printf("%d\n",sum);
     return 0;
 }

