#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int prime[100001],i,j,test,k=0,n,prev;
    long long unsigned res,count;
    memset(prime,1,400004);
    prev=2;
    for(i=2;i<=317;i++){
        if(prime[i]){
	    while(prev<=i) prime[prev++]=i;
            for(j=i*i;j<=100000;j+=i)
            prime[j]=0;
        }
    }
    //for(n=2;n<50;n++) cout<<"("<<n<<" "<<prime[n]<<")"<<"  ";cout<<endl;
    //cout<<i<<"  "<<j<<endl;
    cin>>test;
    while(test--){
        cin>>n>>k;
        res=0;
        for(i=2;i<=n;i++){
            count=0;
            //if(i==prime[i]) count=1;
            //else count=0;
            for(j=prime[i];j<=n;j=prime[j+1]){
                count++;
                if(count==k){
                res+=(n-j)+1;
                break;
                }
            }
        }
        cout<<res<<endl;
    }
}
                            
