#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
unsigned long int res=0,count=0,one=1;
unsigned long int step,p;
char start,dest;
int u[8][8]={{0,1,0,1,1,0,0,0},
             {1,0,1,0,0,1,0,0},
             {0,1,0,1,0,0,1,0},
             {1,0,1,0,0,0,0,1},
             {1,0,0,0,0,1,0,1},
             {0,1,0,0,1,0,1,0},
             {0,0,1,0,0,1,0,1},
             {0,0,0,1,1,0,1,0}};
void pow(int st,int pr,unsigned int stp)
{
    if(stp==1){
    if(u[st][dest-65])  res=(++res)%p;
    }
    else {
    for(int i=0;i<8;i++){
      if(i!=pr && u[st][i]!=0)
      pow(i,st,stp-1);
      }
}
}
int main()
{
cin>>start>>dest;
cin>>step>>p;
pow(start-65,start-65,step);
cout<<res;
}

