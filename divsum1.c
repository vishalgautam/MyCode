#include<stdio.h>
#include<math.h>
int main()
{
    unsigned int cases,sum,numb;
    float num;
    int com=0,temp,prev,div;
    scanf("%u",&cases);
    while(cases--){
        sum=1;prev=0;com=0;
        scanf("%f",&num);
        numb=(int)num;
        if(numb==1||numb==0) printf("0\n");
            else {
            if(numb%2==0){
                div=2;
            	while(1){
                	if(div==prev)break;
                	temp=numb%div;
               		if(!temp){
                    	temp=numb/div;
                    	if(temp==div) {sum+=temp;break;}
                		prev=temp; 
                		sum=sum+div+prev;
                	}
                	div++;
              }
           }
                else {
                     temp=(int)sqrt(num);
                    for(div=3;div<temp;div+=2)
            		if(numb%(div*div)==0) {
                		com=1;
                		break;
                    }
            if(!com) printf("1\n");
                    else {
                        div=2;
            	while(1){
                	if(div==prev)break;
                	temp=numb%div;
                	if(!temp){
                    	temp=numb/div;
                    	if(temp==div) {sum+=temp;break;}
                		prev=temp; 
                		sum=sum+div+prev;
                	}
                	div+=2;
            }
                        
       
         }
     }
     printf("%u\n",sum);
  }
        
}
return 0;}

