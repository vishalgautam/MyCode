#include<stdio.h>
#define UL unsigned long int
UL arr[1000000];
UL suffix[];
UL lq,rq;
UL makesuffix(UL l,UL r, UL ind){
    UL mid=l+(r-l)/2,left,right;
    if(l==r){
        suffix[ind*2+1]=arr[l];
        return arr[l];
    }
    left=makesuffix(l,mid,ind*2+1);
    right=makesuffix(mid+1,r,ind*2+2);
    suffix[ind]=left<right?left:right;
    return suffix[ind];
}
UL query(UL l,UL r,UL ind){
    UL mid=l+(r-l)/2,left,right;
    if(r<lq||l>rq) return MAX_LONG;
    if(l>=lq&&r<=rq) return suffix[ind];
    left=query(l,mid,ind*2+1);
    right=query(mid+1,r,ind*2+2);
    if(left<right)
        return left;
    return right;
}
int main(){
    UL n,i,num,q;
    UL min,count=0;
    scanf("%lu"&n);
    for(i=1;i<=n;i++){
        scanf("%lu",&num);
        arr[i]=num;
    }
    makesuffix(1,n,0);
    scanf("%lu",&q);
    while(q--){
        count=0;
        scanf("%lu%lu%lu",&l,&r,&x);
        min=query(l,r);
        for(i=l;i<=r;i++){
            if(arr[i]^x<min)
                count++;
        }
        printf("
