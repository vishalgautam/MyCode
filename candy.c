#include<stdio.h>
int main(){
    int cd[10000],p,i,each;
    unsigned long long int t;
    while(1){
        scanf("%d",&p);
        if(p==-1)
            break;
        t=0;
        for(i=0;i<p;i++){
            scanf("%d",&cd[i]);
            t+=cd[i];
        }
        each=t/p;
        if(p*each-t!=0)
            printf("-1\n");
        else {
            t=0;
            for(i=0;i<p;i++){
                if(cd[i]<each)
                    t+=each-cd[i];
            }
            printf("%llu\n",t);
        }
    }
    return 0;
}


