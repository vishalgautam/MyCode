#include<iostream>
#include<cstring>
using namespace std;
int main(){
  char a[200],ch;
  int test=1024,bw,carry,t,len,i;
  while(test--){
    cin>>a;
    len=strlen(a);
    if(len==1&&a[0]=='1') cout<<1<<endl;
    else{
    bw=1;carry=0;
    for(i=len-1;i>=0;i--)
    {
      if((ch=a[i]-bw)>='0'){
	bw=0;
	a[i]=ch;
      }
      else {
	a[i]='9';
	bw=1;
      }
      t=(a[i]-'0')*2+carry;
      a[i]='0'+t%10;
      carry=t/10;
    }
    if(carry) cout<<carry;
    cout<<a<<endl;
  }
  }
}