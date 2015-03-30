#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
char total[201],more[201],cld[201],res[201];
int carry,i,j,k,temp=0,rem=0,count=10;
int tl,exl,ri,tli,exi;
while(count--){
cin>>total;
cin>>more;
carry=0;
tl=strlen(total);
exl=strlen(more);
cld[200]='\0';

//this solve x+y=total,x-y=more;

for(exi=exl-1,tli=tl-1,k=199 ; exi>=0 ; exi--, tli--, k--){
if(total[tli]-carry>=more[exi]) {cld[k]=total[tli]-carry-more[exi]+48;carry=0;}
else{
cld[k]=total[tli]+10-more[exi]+48-carry;
carry=1;
}}
for(;tli>=0;tli--,k--){
if(total[tli]-48<carry) {cld[k]=total[tli]+10-carry;carry=1;}
else{cld[k]=total[tli]-carry;carry=0;}
}
k++;
//this solve 2*x=total-more;

i=rem=0;
while(k<200){
temp=rem*10+cld[k++]-48;
res[i++]=temp/2+48;
rem=temp%2;
}
res[i]='\0';
int rsl=strlen(res);
// this calculate value of y;

carry=0;
for(ri=rsl-1,tli=tl-1,k=199;ri>=0;ri--,tli--,k--){
if(total[tli]-carry>=res[ri]) {cld[k]=total[tli]-carry-res[ri]+48;carry=0;}
else{
cld[k]=total[tli]+10-res[ri]+48-carry;
carry=1;
}}
for(;tli>=0;tli--,k--){
if(total[tli]-48<carry) {cld[k]=total[tli]+10-carry;carry=1;}
else{cld[k]=total[tli]-carry;carry=0;}
}
k++;i=0;
while(k!=1&&cld[k]=='0') k++;while(res[i]=='0') i++;
cout<<cld+k;
cout<<endl;
cout<<res+i;
cout<<endl;
}
}
