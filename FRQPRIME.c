#include<stdio.h>
int main(){
    int prime[100001]={0},i,j,test,k,n;
    long long unsigned int res,count;
    for(i=2;i<=317;i++)
        if(!prime[i]){
            for(j=i*i;j<=100000;j+=i)
            prime[j]=1;
        }
    scanf("%d",&test);
    while(test--){
        scanf("%d%d",&n,&k);
        res=0;
        for(i=2;i<=n;i++){
            count=0;
            for(j=i;j<=n;j++){
                if(!prime[j]) count++;
                if(count==k) {res+=(n-j);break;}
                }
                
        }
        
        printf("i=%d j=%d %llu\n",i,j,res);
    }
}
                            
