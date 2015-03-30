#include<iostream>
using namespace std;
int main()
{
  float f,sum;
  int d,no;
  cin>>f;
  while(f!=0.00f){
    sum=0;no=0,d=1;
    while(1){
      no+=1;sum+=1.00f/++d;
      if(sum>f) break;
    }
    cout<<no<<" "<<"card(s)"<<endl;
    cin>>f;
  }
}
    