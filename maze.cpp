#include<iostream>
using namespace std;
int mz[8][8]={{0,0,1,1,1,1,1,1},
	      {1,0,0,0,1,1,1,0},
	      {1,1,1,0,0,0,1,0},
	      {0,1,1,1,1,0,1,0},
	      {1,0,0,0,1,0,1,1},
	      {1,0,1,0,0,0,1,1},
	      {1,0,0,0,1,1,1,1},
	      {1,1,1,0,0,0,1,0}};
bool maze(int st1,int st2,int end1,int end2)
{
	if(st1<=7&&st1>=0&&st2<=7&&st2>=0)
	{
		if(st1==end1&&st2==end2)
		{cout<<"path exist";return true;}
		if(mz[st1][st2]==0)
		{
			mz[st1][st2]=1;
			maze(st1,st2+1,end1,end2);
			maze(st1-1,st2,end1,end2);
			maze(st1+1,st2,end1,end2);
			maze(st1,st2-1,end1,end2);
		}
	}
}
int main()
{
maze(0,0,7,7);
}



