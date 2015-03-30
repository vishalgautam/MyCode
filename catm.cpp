#include<stdio.h>
#include<math.h>
main()
{
	int m,n,test;
	int mux,muy,c1x,c1y;
	int c2y,c2x,w,x,y,z;
	scanf("%d%d",&m,&n);
	scanf("%d",test);
	while(test--)
	{
	    scanf("%d%d%d%d%d%d",&mux,&muy,&c1x,&c1y,&c2x,&c2y;
	    w=abs(mux-c1x);x=abs(muy-c1y);y=abs(mux-c2x);z=abs(muy-c2y);
	    if(mux==c1x&&muy==c1y||mux==c2x&&muy==c2y)
		    printf("NO\n");
	    else if(mux==1||muy==1)
		    printf("YES\n");
	    else if(w==x &&x==y&&y==z)
	            printf("NO\n");
	    //else if(mux >= c1x && mux>=c2x || mux<=c1x && mux<=c2x || muy >=c1y&& muy>=c2y|| muy<=c1y && muy<=c2y)
		 //   cout<<"YES\n";
	    //else if(mux==c1x && mux==c2x || muy==c1y&&muy==c2y)
		//    cout<<"YES\n";
	    else printf("YES\n");
	}
}

