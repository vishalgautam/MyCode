#include<stdio.h>
int num[16],k;
unsigned long long int n,ct=0;
void fun(int lcm,int index,int len){
    int j,x,y,temp,t;
    if(index<=k)
        for(j=index;j<=k;j++){
            if(lcm>num[j]){
                t=x=lcm;
                y=num[j];
            }
            else {
                t=x=num[j];
                y=lcm;
            }
            while(t%y!=0) t+=x;
            temp=n/t;
            //printf("prev LCM=%d new LCM=%d with num=%d and count=%d\n",lcm,t,num[j],temp);
            ct+=(len*temp);
            fun(t,j+1,len*-1);
        }
}
int main(){
    int i,b=1;
    scanf("%llu%d",&n,&k);
    //printf("N=%llu , K=%d\n",n,k);
    for(i=1;i<=k;i++){
        scanf("%d",&num[i]);
        ct+=(n/num[i]);
        if(num[i]==1) b=0;
    }
    if(b)
    for(i=1;i<=k;i++)
        fun(num[i],i+1,-1);
    printf("%llu",n-ct);
    return 0;
}
