#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char start,dest;
unsigned long int i,j,k,temp,a[8][8],t[8][8],m[8][8][8];
bool b=true;
int trav[8][8]={0};
unsigned long int u[8][8]={{0,1,0,1,1,0,0,0},
                           {1,0,1,0,0,1,0,0},
                           {0,1,0,1,0,0,1,0},
                           {1,0,1,0,0,0,0,1},
                           {1,0,0,0,0,1,0,1},
                           {0,1,0,0,1,0,1,0},
                           {0,0,1,0,0,1,0,1},
                           {0,0,0,1,1,0,1,0}};
void mul()
{
    for(i=0;i<8;i++)
     {   
        for(j=0;j<8;j++)
            {
             if(b&&i==j)t[i][j]=0;
             else{
             temp=0;
                for(k=0;k<8;k++)
                temp+=(a[i][k]*a[k][j]);
                t[i][j]=temp;
            }
            }
      }      
    for(i=0;i<8;i++){
      for(j=0;j<8;j++)
      {a[i][j]=t[i][j];cout<<t[i][j]<<" ";}
      cout<<endl;}
      b=false;
      cout<<endl;
}
void pow(int n)
{
    if(n==1);
    else {
    pow(n/2);
    if(n%2!=0)
    {
        mul();
        for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            {
             temp=0;
                for(k=0;k<8;k++)
                 temp+=(a[i][k]*u[k][j]);
                t[i][j]=temp;
             }    
      for(i=0;i<8;i++){
      for(j=0;j<8;j++)
      {a[i][j]=t[i][j];cout<<t[i][j]<<" ";}
      cout<<endl;}
    }
    else
    mul();
   }
}
main()
{
long long p,stage,res=0,x=0;
memcpy(a,u,sizeof(u));
memcpy(t,u,sizeof(u));
cin>>start>>dest;
for(int i=0;i<8;i++)
 for(int j=0;j<8;j++)
  m[i][j][j]=u[i][j];
//for(i=0;i<8;i++)
//{a[i][dest-65]=a[i][start-65]=m[i][start-65]=m[i][dest-65]=0;}
cin>>stage>>p;stage;
pow(stage);
 
 //if(i!=start-65 && i!=dest-65 && (x=t[start-65][i]))
   //     if(u[i][dest-65]) res+=x;                  
    //for(i=0;i<8;i++){
    //for(j=0;j<8;j++) cout<<t[i][j]<<" ";cout<<endl;}
cout<<t[start-65][dest-65]%p;
}
     
