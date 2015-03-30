#include<stdio.h>
int pw(int n,int d){
    
    unsigned long int temp;
    if(d==1) return n;
    temp=pw(n,d/2);
    temp*=temp;
    if(d%2) temp*=n;
    return temp;
}
int main(){
    int d,n,r;
    while(1){
        r=1;
        scanf("%d%d",&n,&d);
        if(!d&&!n) break;
        printf("%u\n",pw(n,d));
    }
}

