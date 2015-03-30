#include<iostream>
using namespace std;
int main()
{
        long int n,m,temp;
        int test;
        cin>>test;
        while(test--)
        {
                cin>>n>>m;
                if(!n&&!m) cout<<"1\n";
                else if(!n||!m) cout<<"0\n";
                else 
                {
                     temp=(n-m)&((m-1)/2);
                     if(temp) cout<<"0\n"; else cout<<"1\n";
                }        
        
        }
}
        
