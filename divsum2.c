#include<stdio.h>
#include<math.h>
int main()
{
unsigned long int test,numb,sum,limit,start,inc,i,divd;
scanf("%lu",&test);
while(test--)
{
sum=1;
scanf("%lu",&numb);
if(numb==1||numb==0) {printf("0\n");continue;}
limit=ceil(sqrt((double)numb));
if(numb%2==0){start=2;inc=1;} else{start=3;inc=2;}
for(i=start;i!=numb&&i<limit;i+=inc)
{
if(numb%i==0){
divd=numb/i;
sum=sum+divd+i;
}
}
if(numb%i==0&&numb/i==limit) sum+=i;
printf("%lu\n",sum);
}
}
