#include<stdio.h>
int main(){
    int x,y,z;
    char e,s[5];
    long int n,temp;
    while(1){
        scanf("%s",s);
        x=*s-'0';y=*(s+1)-'0';z=*(s+3)-'0';
        if(!x&&!y&&!z) break;
        n=(x*10+y);
        while(z--) n*=10;
        temp=1;
        while((temp<<=1)<=n);
        temp/=2;
        if(temp==n) printf("1\n");
        else {
            printf("%ld\n",3+(n-temp-1)*2);
        }
    }
    return 0;
}
