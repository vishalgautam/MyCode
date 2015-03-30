#include<stdio.h>
#include<string.h>
int main()
{
	char st[1010];
	char ch,c;
	int rsl[1009]={0};char rslt[500][1010];
	char num[]={'0','1','2','3','4','5','6','7','8','9'};
	int iml,l,temp,diff;
	int i,no,m=0,n,b1=0;
	int b,q,count,x,y;
	int index[510],noz;
	scanf("%d",&no);
	while(no--)
	{
		i=0;b=0;q=0;b1=0;
		count=1008;
		
		scanf("%s",st);
		l=strlen(st);
		m=0;
		
		while(ch=st[i])
		{
			if(ch=='+'||ch=='-'||ch=='*')
			{
				c=ch;
				break;
			}
			i++;
		}
		iml=i>(l-i)?i:(l-i);
		x=i-1;
		y=l-1;
		temp=x+1-(y-i);
		diff=l-i;
		printf("\n");
		switch(c)
		{
			
			case'+':
				while(1)
				{
					if(x<0&&st[y]=='+') break;
					else if(x>=0 && st[y]!='+') { q=(st[x]-'0')+(st[y]-'0')+b;x--;y--; }
					else if(x>=0) { q=(st[x]-'0')+b;x--; }
					else { q=(st[y]-'0')+b;y--;}
					if(q==10)
					{
						b=1;
						rsl[count--]=0;
						continue;
					}
					else if(q>10)
					{
						b=1;
						q=q-10;
					}
					else b=0;
					rsl[count--]=q;
				}
				if(b) rsl[count--]=1;
				st[i]='\0';if(iml<1008-count) iml=1008-count;
				 printf("%*s\n",iml,st);
				 st[i]='+';
				 printf("%*s\n",iml,st+i);
				 b=iml;
				 while(b--) printf("-");printf("\n");
				 if(iml-1==1008-count) printf(" ");
				 while(count<1008) {printf("%c",num[rsl[++count]]);rsl[count]=0;}
				 printf("\n\n");
				 break;
			case '-':
				while(x>=0&&st[y]!='-')
				{
					if((st[x]-'0'-b)>(st[y]-'0')) {rsl[count--]=st[x]-'0'-b-(st[y]-'0');b=0;}
					else if((st[x]-'0'-b)<(st[y]-'0')) {rsl[count--]=st[x]-'0'-b+10-(st[y]-'0');b=1;}
					else {rsl[count--]=0;b=0;}
					x--;y--;
				}
				while(x>=0) 
				{
					if(st[x]-'0'-b<0) 
						rsl[count--]=st[x--]-'0'-b+10;
					else {
						rsl[count--]=st[x--]-'0'-b;
						b=0;
					     }
				}
				st[i]='\0';
				 printf("%*s\n",iml,st);
				 st[i]='-';
				 printf("%*s\n",iml,st+i);
				 while(count<1008) {if(rsl[count]!=0) break;count++;} 
				 b=iml;
				 b1=1008-count+1;
				 if(diff>b1) temp=b-diff; else {temp=b-b1;diff=b1;}
				while(temp--)printf(" ");
				while(diff--) printf("-");printf("\n");
				temp=iml-b1;while(temp--) printf(" ");
				if(count==1008&&rsl[count]==0) printf("0");
				 else while(count<=1008) 
				 {
				 	printf("%c",num[rsl[count]]);rsl[count++]=0;
				 }
				 printf("\n\n");
				 break;		
			case '*':while((ch=st[y--])!='*')
				{
					temp=x;
					noz=count--;
					n=1008;
					rslt[m][1009]='\0';
					while(temp>=0)
					{
						
						q=(ch-'0')*(st[temp--]-'0')+b;
						b=q/10;
						rslt[m][n--]=num[q%10];
						if(ch=='0') break;
						q=rsl[noz]+q%10+b1;
						rsl[noz--]=q%10;
						b1=q/10;
					}
					if(b)
					{
						rslt[m][n--]=num[b];
						q=(rsl[noz]+b1+b)%10;
						b1=q/10;
						rsl[noz--]=q%10;
					}
					if(b1) rsl[noz--]=1;
					index[m++]=++n;
					b=b1=0;
				}
				b=(1008-noz)>iml?(1008-noz):iml;
				st[i]='\0';
				 printf("%*s\n",b,st);
				 st[i]='*';
				 printf("%*s\n",b,st+i);
				b1=1008-index[0]+1;
				if(diff>b1) temp=b-diff; else {temp=b-b1;diff=b1;}
				while(temp--)printf(" ");
				while(diff--) printf("-");
				printf("\n");
				b1=b;
				for(i=0;i<m;i++) {printf("%*s",b1--,rslt[i]+index[i]);printf("\n");}
				if(m==1) {for(i=noz+1;i<=1008;i++) rsl[i]=0;printf("\n");break;}
				if(b>1008-noz) printf(" ");
				b1=1008-noz;
				while(b1--)printf("-");printf("\n");
				if(b>1008-noz) printf(" ");
				for(i=noz+1;i<=1008;i++){printf("%c",num[rsl[i]]);rsl[i]=0;}
				printf("\n\n");
				break;	
		}
	}
return 0;}
