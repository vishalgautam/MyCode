#include<iostream>
using namespace std;
int main(){
	unsigned int test,i,j,sum=0,temp=0;
	cin>>test;
	bool b=true;
		for(j=1;b;j++){
			for(i=1;i*j<=test;i++) if(i>=j) temp++;
			if(temp==sum) b=false;
			else sum=temp;
		}
		cout<<sum;
	}
		
		
