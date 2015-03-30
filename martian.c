#include<stdio.h>
int main(){
    int y[501][501],b[501][501],yen[501][501],blog[501][501];
    long int sum=0;
    int row,col,i,j;
    unsigned long long int left[501][501],up[501][501];
    while(1){
        row=col=0;
        scanf("%d%d",&row,&col);
        if(!row&&!col) break;
        for(i=1;i<=row;i++)
            for(j=1;j<=col;j++){
                left[i][j]=up[i][j]=yen[i][j]=blog[i][j]=0; 
                scanf("%d",&y[i][j]);
	    }
        for(i=1;i<=row;i++)
            for(j=1;j<=col;j++)
                scanf("%d",&b[i][j]);
	for(i=1;i<=row;i++)
		for(j=1;j<=col;j++)
		{
			yen[i][j]=yen[i][j-1]+yen[i-1][j]+y[i][j]-yen[i-1][j-1];
			blog[i][j]=blog[i][j-1]+blog[i-1][j]+b[i][j]-blog[i-1][j-1];
			left[i][j]=(left[i-1][j]>up[i-1][j]?left[i-1][j]:up[i-1][j])+yen[i][j]-yen[i-1][j];
			up[i][j]=(up[i][j-1]>left[i][j-1]?up[i][j-1]:left[i][j-1])+blog[i][j]-blog[i][j-1];
		}
	printf("%llu\n",left[row][col]>up[row][col]?left[row][col]:up[row][col]);
    }
    return 0;
}
         
