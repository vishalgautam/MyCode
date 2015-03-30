#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
int main()
{
	char a[1001],ch;
	int no,low,high,i;
	int len,sp,m,car;
	int tmp,ll,hl;
	cin>>no;
	while(no--)
	{
		cin>>a;
		len=strlen(a);
		i=0;
		while(a[i])
		{
			if(a[i]=='+'||a[i]=='-'||a[i]=='*')
			{
				ch=a[i];
				a[i]='\0';
				break;
			}
			i++;
		}
		switch(ch)
		{
			case '+':
				m=len-i-1;
				sp=(m>i?m:i)+1;
				if(m>i)
				{
					high=len-1;
					low=i-1;
					hl=i+1;
					ll=0;
				}
				else
				{
					high=i-1;
					low=len-1;
					hl=0;
					ll=i+1;
				}
				cout<<setw(sp)<<a<<endl;
				a[i]='+';
				cout<<setw(sp)<<a+i<<endl;
				a[i]='\0';
				for(int k=1;k<=sp;k++) cout<<"-";cout<<endl;
				car=0;
				for(;low>=ll;low--,high--)
				{
					tmp=(a[low]-'0')+(a[high]-'0')+car;
						if(tmp>9)
						{
							car=1;
							tmp-=10;
							a[high]=tmp+'0';
						}
						else a[high]=tmp+'0';
				}
				for(;high>=hl;high--)
					if(ch&&a[high]=='9')
					{
						a[high]='0';
						ch=1;
					}
					else {a[high]+=ch;break;}
				if(high<hl&&ch)
					cout<<"1"<<a+hl<<endl;
				else cout<<setw(sp)<<a+hl<<endl;
				break;
		}
	}
}
