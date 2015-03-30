#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
    int test=11,i;//,x=1,y=1;
    int alpha[26]={11,12,13,14,15,21,22,23,24,24,25,31,32,33,34,35,41,42,43,44,45,51,52,53,54,55};
    const char *buff;
    char c;
    string str;
    /*
    for(i=0;i<8;i++){
        if(y==6) {
            x++;
            y=1;
        }
        alpha[i]=x*10+y;
        y++;
    }
    alpha[i++]=x*10+y;
    alpha[i++]=x*10+y;
    y++;
    for(;i<26;i++){
        alpha[i]=x*10+y;
        y++;
        if(y==6){
            x++;
            y=1;
        }
    }
    for(i=0;i<26;i++)
        printf("%d,",alpha[i]);
        */
    scanf("%d",&test);
    getchar();
    while(test--){
        getline(cin,str);
        buff=str.c_str();
        for(i=0;c=buff[i];i++)
            if(c!=' ')
                printf("%d ",alpha[c-'A']);
        printf("\n");
    }
    return 0;
}
