#include<stdio.h>
main()
{
unsigned int test,no,sum,div,last;
int inc,stop;
scanf("%u",&test);
while(test--)
{
sum=1;
scanf("%u",&no);
if(no==1) printf("0\n");
else{
if(no&1==0) {div=2;inc=1;} else {div=3;inc=2;}
stop=no>>1;
last=0;
while(div<=stop){
if(no%div==0) {
if(no/div==div){ sum+=div;break;}
else if(last==div) break;
else{
last=no/div;
sum=sum+div+last;
}
}
div+=inc;
}
printf("%u\n",sum);
}
}
}

