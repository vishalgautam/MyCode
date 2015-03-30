#include<stdio.h>
int main(){
    int test,count,i,j,k=0;
    long long int stm,frd,of[1000],t,tmp;
    scanf("%d",&test);
    while(k++<test){
        t=count=0;
        scanf("%lld%lld",&stm,&frd);
        for(i=0;i<frd;i++){
            scanf("%lld",&of[i]);
            t+=of[i];
        }
        if(stm>t) printf("Scenario #%d:\nimpossible\n\n",k);
        else {
            for(i=0;i<frd;i++){
                t=i;
                for(j=i+1;j<frd;j++)
                    if(of[j]>of[t])
                        t=j;
                tmp=of[i];
                of[i]=of[t];
                of[t]=tmp;
                stm-=of[i];
                count++;
                if(stm<=0){
                    printf("Scenario #%d:\n%d\n\n",k,count);
                    break;
                }
            }
        }
    }
    return 0;
}

