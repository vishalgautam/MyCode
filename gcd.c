#include<stdio.h>
main(){
    char c;
    int num=0;
    while(1){
        scanf("%c",&c);
        if(c=='\n') break;
        num=num*10+c-'0';
    }
    printf("%d",num);
}
