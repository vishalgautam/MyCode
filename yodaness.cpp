#include<iostream>
#include<map>
#include<string>
#include<stdio.h>
std::map<std::string,int> Map;
int arr[30000];
int  c[30000];
unsigned long long int count;
using namespace std;
void merge(int s,int m,int e){
    int i=s,j=m+1,k=0;
    while(i<=m&&j<=e){
        if(arr[i]<arr[j]){
            c[k++]=arr[i++];
        }
        else {
            c[k++]=arr[j++];
            count=count+(m-i+1);
        }
    }
    while(i<=m){
        c[k++]=arr[i++];
    }
    while(j<=e){
        c[k++]=arr[j++];
    }
    i=s;j=0;
    while(j<k){
        arr[i++]=c[j++];
    }
}
void mergesort(int s,int e){
    if(s<e){
        int mid=s+(e-s)/2;
        mergesort(s,mid);
        mergesort(mid+1,e);
        merge(s,mid,e);
    }
}
int main(){
    int T,N,j;
    string str;
    char w[30001];
    //std::ifstream cin("input.txt");
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        for(j=0;j<N;j++){
            scanf("%s",w);
            str=w;
            Map[str]=j+1;
            
        }
        for(j=0;j<N;j++){
            scanf("%s",w);
            str=w;
            arr[j]=Map[str];
        }
        count=0;
        mergesort(0,N-1);
        printf("%llu\n",count);
    }
    return 0;
}
