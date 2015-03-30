#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
	char a[1000000];
	int no,i,j;
	bool b;
	int len;
	cin>>no;
	while(no--)
	{
		cin>>a;j=i=0;b=true;
		while(a[i])
			if(a[i++]!='9') {b=false;break;}
		if(b)
		{
			a[j]='1';
			for(j=1;j<i;j++)
				a[j]='0';
			a[j]='1';
			a[++j]='\0';
			cout<<a<<endl;
			continue;
		}
		len=strlen(a);
		if(len%2==0)
		{
			j=len/2;
			i=j-1;
		}
		else i=j=len/2;
		b=false;
		while(i>=0&&j<len)
		{
			if(a[i]>a[j]){
				b=true;break;
			}
			else if(a[i]<a[j]){
				b=false;break;
			}
			i--;j++;
		}
		j=len-1;i=0;
		while(i<j)
			a[j--]=a[i++];
		if(b) 
			cout<<a<<endl;
		else 
		{
			if(i>j){
			i--;j++;
		       }
		while(i>=0&&j<=(len-1))
		{
			if(a[i]<'9'){
				a[j]=a[i]=a[i]+1;break;
			}
			else a[j]=a[i]='0';
			i--;j++;
		} cout<<a<<endl;
		}
	}
}
			




