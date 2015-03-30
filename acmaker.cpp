#include<iostream>
#include<set>
#include<string>
char word[140];
char *lastcase="LAST CASE";
bool line(){
    int count=0,i=0,wc=0;
    while(1){
        scanf("%c",&c);
        if(c=='\n')
            break;
        if(c==' '){
            wc++;
        }
        word[i++]=c;
    }
    if(i==9&&strncmp(word,lastcase,9)==0)
        return false;
    return true;
}
using namespace std;
int main(){
    int t,i,j;
    set<string> insg;
    while(1){
        cin>>t;
        if(!t) break;
        for(i=0;i<t;i++){
            scanf("%s",word);
            str=w;
            insg.insert(str);
        }
        while(1){
                line();
