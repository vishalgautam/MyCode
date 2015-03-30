#include<stdio.h>
#include<stdlib.h>
int *a;
long int num;
int sort(int s,int e){
    if(s<e){
        int t,p=a[e],i=s-1,j;
        //printf("%d  %d\n",s,e);
        //if(s<0||e<0) return 0;
        for(j=s;j<e;j++){
            if(a[j]<=p){
                i++;
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
        t=a[++i];
        a[i]=p;
        a[e]=t;
        sort(s,i-1);
        sort(i+1,e);
    }
}

int main(){
    unsigned int n,k,i,j,t;
    long long int temp,ct=0,max;
    scanf("%u%u",&n,&k);
    a=(int *)malloc(sizeof(int)*n);

    for(i=0;i<n;i++) {
    	scanf("%d",&a[i]);
    }
    sort(0,n-1);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if((t=a[j]-a[i])==k)
                ct++;
            else if(t>k) break;
        }
    }
    printf("%llu\n",ct);
    return 0;
}
