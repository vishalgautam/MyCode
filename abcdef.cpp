#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v;
	vector<int>::iterator it;
	pair<vector<int>::iterator,vector<int>::iterator> bound;
	int n,i,j,k,sum=0;
	int temp;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++) cin>>a[i];
	   for(i=0;i<n;i++)
		for(j=0;j<n;j++)
 		   for(k=0;k<n;k++)
   			{
   			   temp=a[i]*a[j]+a[k];
   			   v.push_back(temp);
   			}
   	sort(v.begin(),v.end());
	for(i=0;i<n;i++)
          for(j=0;j<n;j++)
  	    for(k=0;k<n;k++)
   		{
   			if(a[k]!=0)
   			{
    			 temp=(a[i]+a[j])*a[k];
    			 bound=equal_range(v.begin(),v.end(),temp);
    			 sum=sum+bound.second-bound.first;
    			}
    		}
cout<<sum;
return 0;
}
