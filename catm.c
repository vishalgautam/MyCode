#include<stdio.h>
#include<math.h>
int main()
{
	int m,n,test;
	int mux,muy,c1x,c1y;
	int c2y,c2x,w,x,y,z;
	scanf("%d%d",&m,&n);
	scanf("%d",&test);
	while(test--)
	{
	    scanf("%d%d%d%d%d%d",&mux,&muy,&c1x,&c1y,&c2x,&c2y);
	    w=(int)abs(mux-c1x);
	    x=(int)abs(muy-c1y);
	    y=(int)abs(mux-c2x);
	    z=(int)abs(muy-c2y);
	    if(mux==c1x&&muy==c1y||mux==c2x&&muy==c2y)
		    printf("NO\n");
	    //else if(mux==1||muy==1)
		   // printf("YES\n");
	    if(mux<c1x&&mux<c2x||mux>c1x&&mux>c2x||muy<c1y&&muy<c2y||muy>c1y&&muy>c2y)
		    printf("YES\n");
	    else if(w==x &&y==z)
	            printf("NO\n");
	    else printf("YES\n");
	}
return 0;
}

