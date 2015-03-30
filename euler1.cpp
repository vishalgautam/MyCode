#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
	long unsigned int test,num=1000001,e,k,p;
	float res;
	long long int prime[num];
	memset(prime,0,num*sizeof(int));
	prime[1]=prime[0]=1;
	for(p=2;p<=num;p++){
		if(!prime[p]){
			prime[p]=p;
			for(k=1;k*p<=num;k++)
				prime[k*p]=p;
		}
	}
	cin>>test; 
	while(test--){
		cin>>num;
		if(num==1) {
			cout<<'1'<<endl;
			continue;
		}
		else {
			res=1;
			while(num>1){
				p=prime[num],e=0;
				for(;num%p==0;e++,num/=p);
				res*=(pow(p,e-1)*(p-1));
			}
			cout<<res<<endl;
		}
	}
}
