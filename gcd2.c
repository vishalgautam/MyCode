#include<stdio.h>
#include<string.h>
int main(){
    int test,i,len;
    char s[251];
    unsigned int b,a,t,num;
    scanf("%d",&test);
    while(test--){
        scanf("%u%s",&b,s);
        if(b==0) {
            printf("%s\n",s);
            continue;
        }
        num=0;
        len=strlen(s);
        for(i=0;i<len;i++){
            num=num*10+s[i]-'0';
            num=num-(num/b)*b;
        }
        a=b;
        b=num;
        while(b!=0){
            t=b;
            b=a-(a/b)*b;
            a=t;
        }
        printf("%u\n",a);
    }
    return 0;
}
