#include<iostream>
#include<cstring>
using namespace std;
int m[2][2]={{1,1},{1,0}},t[2][2],a[2][2],i,j,k,temp;
void power(long unsigned int n){
  if(n==1);
  else if(n%2==0)
  {
    power(n/2);
    for(i=0;i<2;i++)
     {
        for(j=0;j<2;j++)
            {
             temp=0;
                for(k=0;k<2;k++)
                temp+=(a[i][k]*a[k][j]);
                t[i][j]=temp%10;
            }
      }
      memcpy(a,t,sizeof(t));
   }
  else{
    power(n/2);
    for(i=0;i<2;i++)
     {
        for(j=0;j<2;j++)
            {
             temp=0;
                for(k=0;k<2;k++)
                temp+=(a[i][k]*a[k][j]);
                t[i][j]=temp%10;
            }
      }
      memcpy(a,t,sizeof(t));
     for(i=0;i<2;i++)
     {
        for(j=0;j<2;j++)
            {
             temp=0;
                for(k=0;k<2;k++)
                temp+=(a[i][k]*m[k][j]);
                t[i][j]=temp%10;
            }
      }
      memcpy(a,t,sizeof(t));
  }
}
int main(){
  int test;
  cin>>test;
  long unsigned int no;
  while(test--){
    cin>>no;
    memcpy(a,m,sizeof(m));
    if(no==1) cout<<0<<endl;
    else if(no==2||no==3) cout<<1<<endl;
    else {
    power(no-1);
    //cout<<a[0][0]<<" "<<a[0][1]<<"\n"<<a[1][0]<<" "<<a[1][1]<<endl;
    cout<<a[0][1]%10<<endl;
    }
  }
}