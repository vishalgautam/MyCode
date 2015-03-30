#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
bool a[32003]={0},b[100001]={0};
int main()
{
    int m,n,t,i,j;
    for(i=2;i<sqrt(32003);i++) {
        if(a[i]==0) {
            for(j=i<<1;j<32003;j+=i) {
                a[j]=1;
            }
        }
    }
    cin>>t;
    while(t--) {
        cin>>m>>n;
        if(m==1) m++;
        memset(b,0,sizeof b);
        for(i=2;i<=(int)sqrt(n);i++) {
            if(a[i]==0) {
                for(j=(((m-1)/i)+1)*i;j<=n;j+=i) {
                    if(j<32000) {
                        if(a[j])
                        b[j-m]=1;
                        }
                    else
                        b[j-m]=1;
                    }
                }
            }
        for(j=0;j<=n-m;j++) {
            if(b[j]==0)
                printf("%d\n",j+m);
            }
        cout<<endl;
        }
    return 0;
}


