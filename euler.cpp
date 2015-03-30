#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
	unsigned int test,num=1000000,root,k,i,p;
	double res;
	char st[1000009];
	memset(st,'1',1000000);
	st[1]='0';
	root=(int)sqrt(num);
	for(p=3;p<=root;p+=2){
		if(st[p]=='1'){
			for(k=p*p;k<=num;k+=p)
				st[k]='0';
		}
	}
	cin>>test; 
	while(test--){
		cin>>num;
		res=num;
		if(num%2!=0&&st[num]=='1') cout<<num-1<<endl;
		else {
			if(num%2==0) res*=1.0/2.0;
			for(i=3;i<=num/2;i+=2){
				if(st[i]=='1'&&num%i==0){
					res*=((float)(i-1)/i);}
			}
			cout<<res<<endl;
		}
	}
}
