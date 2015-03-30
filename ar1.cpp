#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
int main()
{
	char a[1001],ch;
	int no,low,end,i;
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
				break;
			}
			i++;
		}
				j=i-1;
				end=len-1;
				car=0;
				for(;a[end]!=ch&&j>=0;j--,end--)
				{
					tmp=(a[j]-'0')+(a[end]-'0')+car;
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
