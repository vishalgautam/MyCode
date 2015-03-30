#include<iostream>
using namespace std;
int main(){
	long long int i,rel,rem;
	char arr[1000];
	arr[999]='\0';
	int k=998;
	cin>>i;
	if(!i) cout<<'0';
	else{
	while(i!=1&&i!=0){
		rel=i/-2;
		rem=i%-2;
		if(rem==0) arr[k--]='0';
		else if(rel<0) arr[k--]='1';
		else {arr[k--]='1';rel++;}
		i=rel;
	}
	if(i==1) arr[k--]='1';k++;
	while(arr[k]=='0') k++;
	cout<<arr+k;
}
}
