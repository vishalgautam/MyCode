#include<stdio.h>
#include<stdlib.h>
int main(){
    unsigned long long int test,i,t,j=1;
    unsigned long long int candy,child;
    scanf("%llu",&test);
    while(j++<=test){
        getchar();
        scanf("%llu",&child);
        if(child==0) printf("YES\n");
        else {
            t=0;
            for(i=0;i<child;i++){
                scanf("%llu",&candy);
                t+=candy;
                t%=child;
            }
            if(t==0)
                printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
