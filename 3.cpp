#include<iostream>
using namespace std;
int p(char ch)
{
	switch(ch)
	{
		case '+':return 1;
		case '-':return 2;
		case '*':return 3;
		case '/':return 4;
		case '^':return 5;
	}
}	
int main()
{
	char op[200],ex[400];
	int top,no,i;
	cin>>no;
	while(no--)
	{
		cin>>ex;
		i=top=0;
		while(ex[i])
		{
			if(ex[i]>='a'&&ex[i]<='z')
				cout<<ex[i];
			else if(ex[i]==')')	
				while(op[--top]!='(')
					cout<<op[top];
			else if(ex[i]!='(')
			{
				while(top && op[top-1]!='(' &&  p(op[top-1])>p(ex[i]) )
					cout<<op[--top];
				op[top++]=ex[i];
			}
			else op[top++]=ex[i];
			i++;
		}
		while(top && op[top-1]!='(') cout<<op[--top];
		cout<<endl;
	}
}

