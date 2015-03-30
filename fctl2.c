#include<stdio.h>
#include<string.h>
main()
{
  char  rsl[200],t[200],num[]={'0','1','2','3','4','5','6','7','8','9'};
 int test,numb,index,ti,i,j,flag,carry,mul,rl,temp,sum;
scanf("%d",&test);
while(test--)
{
memset(t,'0',200);
memset(rsl,'0',200);
ti=0;
scanf("%d",&numb);
temp=numb;
while(temp){ t[ti++]=num[temp%10]; temp=temp/10;}
while(--numb>1)
{
                        temp=numb;
                        j=0;
                        while(temp)
                        {
                                mul=temp%10;
                                temp=temp/10;
                                index=0;i=j++;
                                flag=carry=0;
                                if(mul==0) rsl[i++]='0';
                                else  
                                {
                                        while(index<ti)
                                        {
                                        rl=mul*(t[index++]-'0')+carry;
                                        carry=rl/10;
                                        sum=rl%10+(rsl[i]-'0')+flag;
                                        flag=sum/10;
                                        rsl[i++]=num[sum%10];
                                        }  
                                        if(carry) 
                                        {
                                                sum=carry+(rsl[i]-'0')+flag;
                                                rsl[i++]=num[sum%10];
                                                flag=sum/10;
                                        }
                                        if(flag) rsl[i++]='1';
                                }

                        }
                        ti=i;
                        memcpy(t,rsl,i);
                        memset(rsl,'0',i+10);
                  }
                  for(j=ti-1;j>=0;j--) printf("%c",t[j]); printf("\n");
                  
         }
}                       
