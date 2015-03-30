#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#define max 100000
using namespace std;
int ne,prev;
bool find(int n,int *b,int l,int r){
	int mid,c;
	while(l<r){
		mid=l+r/2;
		if((c=b[mid])==n){
			prev=ne;
			ne=mid;
			return true;
		}
		else if(c<n) l=mid+1;
		else r=mid-1;
	}
	return false;
}
int main(){
	int test1,test2,mid,sum=0,i,j,sum1=0,value;
	bool bl;
	while(1){
		string line,line1;
		getline(cin,line);
		stringstream linestream(line);
		linestream>>test1;
		if(!test1) break;
		int a[test1];i=0;
		while(linestream>>value) a[i++]=value;
		cout<<"vishal\n";
		getline(cin,line1);
		stringstream::str(line1);
		linestream>>test2;
		int b[test2];
		i=0;
		while(linestream>>value) b[i++]=value;
		i=j=0;
		ne=prev=0;
		mid=b[0];
		
		while(i<test1){
			sum1+=a[i];
			bl=find(a[i],b,ne,test2-1);
			if(bl&&ne<test2){
				j=ne;
				while(j>prev) mid+=b[j--];
				sum+=(mid>sum1)?mid:sum1;
				mid=sum1=0;
			}
			i++;
		}
		while(ne<test2) mid+=b[ne++];
		sum+=(mid>sum1)?mid:sum1;
		cout<<sum<<endl;sum=sum1=mid=0;
	}
}
