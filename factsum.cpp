#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  int test;
  long long unsigned int no;
  long double temp,s;
  cin>>test;
  while(test--){
    cin>>no;
    if(no==0||no==1) cout<<1<<endl;
    else{
    temp=log10(2*M_PI*no)/2;
    s=no*log10(no/M_E);
    temp+=s;
    cout<<(long long unsigned int)ceil(temp)<<endl;
    }
  }
}
    
