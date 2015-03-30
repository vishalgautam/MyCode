#include<stdio.h>
typedef unsigned long long int ULL;
ULL count(int k,int n){
    ULL c=1,sum=1;
   int i; 
    for(i=1;i<=n;i++){
        c*=k;
        c%=10;
        sum=sum+c;
        
    }
    return sum;
}
ULL weirdness(int sum){
    ULL temp=0;
    while(sum){
        temp=temp+sum%10;
        sum=sum/10;
    }
    return temp;
}
int main(){
    int T,N,K,i;
    ULL no;
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        scanf("%d%d",&K,&N);
        no=0;
        no=count(K,N);
        //printf("no of nodes: %llu\n",no);
        printf("%llu\n",weirdness(no));
    }
    return 0;
}

