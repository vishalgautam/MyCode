#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main(){
    const char *line;
    char c,p;
    string str;
    int test,s,e,max,i,j,prev,count;
    scanf("%d",&test);
    getchar();
    while(test--){
        line=NULL;
        max=prev=count=0;
        getline(cin,str);
        line=str.c_str();
        if(*line=='\0'){
            test++;
            continue;
        }
        p=0;
        i=0;
        while((c=line[i])!='\0'&&c==' ') i++;
        if(c!='\0')
        for(j=i;;i++){
            c=line[i];
            //printf("%c",c);
            if(c==' '||c=='\0'){
                if(i-j==prev){
                    count++;
                    j=i+1;
                    max=max>count?max:count;
                    //printf("equal %d ",count);
                }
                else {
                    max=count>max?count:max;
                    //printf("unequal %d ",max);
                    count=1;
                    prev=i-j;
                    j=i+1;
                }
                while((c=line[i])!=0&&c==' ') j=++i;
            }
            if(c=='\0') break;
        }
        printf("%d\n",max);
    }
    return 0;
}
