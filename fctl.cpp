#include<iostream>
using namespace std;
int main()
{
	unsigned long int num;
	long int t;
	long int zero,div;
	cin>>t;
	while(t--)
	{
	        zero=0;
	        div=5;
	        cin>>num;
	        while(num/div>0)
	        {
	                zero+=(int)(num/div);
	                div*=5;
	        }
	        cout<<zero<<endl;
	}
}
