#include<cstdio>
int main(){
    int a[1423],n,i,j,k,temp,b=1;
    while(1){
        b=1;
        scanf("%d",&n);
        if(!n) break;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++){
            for(j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]){
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        for(i=1;i<n;i++){
            if(a[i]-a[i-1]>200){
                b=0;
                break;
            }
        }
        if(!b||2*(temp=1422-a[n-1])>200)
            printf("IMPOSSIBLE\n");
        else printf("POSSIBLE\n");
    }
    return 0;
}
