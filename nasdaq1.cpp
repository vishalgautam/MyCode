#include<algorithm>
#include<cstdio>
int main(){
    long truck[1000];
    long box[1000];
    int n,m,bi,ti,count=0,start=0;
    long weight,capacity;
    scanf("%d%d",&n,&m);
    for(bi=0;bi<n;bi++){
        scanf("%ld",&weight);
        box[bi]=weight;
    }
    
    for(ti=0;ti<m;ti++){
        scanf("%ld",&capacity);
        truck[ti]=capacity;
    }
    std::sort(box,box+n);
    std::sort(truck,truck+m);
    bi=ti=0;
    //printf("%ld  %ld\n",*truck,*(truck+1));
    while(1){
        ti=start;
        while(ti<m && bi<n){
            if(truck[ti]>=box[bi]){
                ti++;
                bi++;
            }
            else {
                start=ti++;
            }
        }
        if(bi<n) count+=2;
        else {
            count++;
            break;
        }
    }
    printf("%d",count);
    return 0;
}
