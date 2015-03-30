#include<stdio.h>
int main(){
    int n,i,temp,count[4];
    char *in,*out;
    scanf("%d",&n);
    count[0]=count[1]=count[2]=count[3]=n;
    temp=n*2;
    in=(char*)malloc(temp);
    out=(char*)malloc(temp);
    scanf("%s",in);
    for(i=0;i<temp;i++)
        count[in[i]-'A']--;

