#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int prim[16000],m,n;
	int i,j,k=0,no,root;
	cin>>no;
	bool a[100001]={1},cap=true;
	prim[0]=3;
	for(i=3;i<=32003;i+=2)
	{
		root=sqrt(i)+1;
		for(j=0;prim[j]&&prim[j]<=root;j++)
			if(i%prim[j]==0)
			{
				cap=0;
				break;
			}
		if(cap)
			prim[k++]=i;
		cap=1;
	}
	int p,start;
	j=0;
	while(no--)
	{
		cin>>m>>n;
		if(m==1) m++;
	for(i=0;i<k;i++)
	{
		p=prim[i];
		if(p&&p<m)
			start=m+(p-m%p);
		else start=2*p;
		for(;start<=n;start+=p)
			a[start-m]=0;
	}
	for(i=0;i<=n-m;i++)
		if(a[i]&&(m+i)%2!=0)
			cout<<m+i<<" ";
	cout<<endl;
	memset(a,1,sizeof a);
	}
}
