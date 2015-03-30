#include<iostream>
#include<string>
#include<sstream>
#include<climits>
using namespace std;
int main(){
    int n,e[10][10],prob[10][10],root[10][10];
    int key[10],dummy[10],i=1,j,num,min;
    string str;
    getline(cin,str);
    stringstream keys(str);
    while(keys>>num) key[i++]=num;
    n=i;
    i=0;
    str.clear();
    getline(cin,str);
    stringstream dummys(str);
    while(dummys>>num) dummy[i++]=num;
    for(i=1;i<=n;i++){
        e[i][i-1]=dummy[i-1];
        prob[i][i-1]=dummy[i-1];
    }
    for(int l=1,rt,t,r;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            prob[i][j]=prob[i][j-1]+dummy[j]+key[j];
            min=INT_MAX;
            for(r=i;r<=j;r++){
                t=e[i][r-1]+e[r][j]+prob[i][j];
                if(min>t){
                    min=t;
                    rt=r;
                }
            }
            e[i][j]=min;
            root[i][j]=rt;
        }
    }
    cout<<e[1][n];
    return 0;
}
