#include<iostream>
using namespace std;
int main()
{
        char num[]={'0','1','2','3','4','5','6','7','8','9'};
        char x[1000],y[1000];
        char rsl[10000];
        int xc,yc,test,temp,flag,i;
        cin>>test;
        while(test--)
        {
                xc=yc=0;
                i=temp=flag=0;
                cin>>x>>y;
               while(x[xc]||y[yc])
               {        
                        if(x[xc]&&y[yc]) temp=(x[xc++]-'0')+(y[yc++]-'0')+flag;
                        else if(x[xc]=='\0') temp=(y[yc++]-'0')+flag;
                        else temp=(x[xc++]-'0')+flag;       
                        if(temp>=10) {temp=temp-10;flag=1;}
                        else flag=0;
                        rsl[i++]=num[temp];
               }
               if(flag) rsl[i++]='1';rsl[i]='\0';
               i=0;
               while(rsl[i]) if(rsl[i]=='0') i++; else break;
               cout<<rsl+i<<endl;
        }
}
