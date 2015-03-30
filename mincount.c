#include<stdio.h>
int main(){
    unsigned long long int test,num,n;
    unsigned long long int res;
    scanf("%lld",&test);
    while(test--){
        scanf("%lld",&num);
        res=0;
        if(num%2==res){
            n=num/2;
            res=n/2*((n-1)*2)+1;

        }
        else {
            n=num/2+1;
            res=n/2*((n-1)*2);
        }
        printf("%llu\n",res);

    }
    return 0;
}
