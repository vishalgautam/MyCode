#include<iostream>
#include<string.h>
using namespace std;
void lcs(char s[],char t[])
{
	int sl=strlen(s)+1;
	int tl=strlen(t)+1,m,n;
	int mat[sl][tl],i,j,k,count;
	for(i=0;i<sl;i++) mat[i][0]=0;
	for(i=0;i<tl;i++) mat[0][i]=0;
	for(i=1;i<sl;i++)
	{
		for(j=1;j<tl;j++)
		{
			if(s[i]==t[j]) 
			mat[i][j]=mat[i-1][j-1]+1;
			else
			{
				m=mat[i-1][j];
				n=mat[i][j-1];
				mat[i][j]=m>n?m:n;
			}
		}
	}
	cout<<"maximum lenth of subse\n"<<mat[sl-1][tl-1]<<endl;
}
int main()
{
	char s[]="vishal";
	char t[]="aaavishaaa";
	lcs(s,t);
}
