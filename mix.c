#include<stdio.h>
int main(){
	int matrix[101][101];
	int i,sum,j,k,c,cur;
	int no,color[101],mix[100][100];
	int x;
	while(scanf("%d",&no)!=EOF){
		for(i=1;i<=no;i++){
			scanf("%d",&color[i]);
			mix[i][i]=color[i];
		}

	    matrix[1][1]=0;
	    for(j=2;j<=no;j++){
		    matrix[j][j]=0;
		    for(i=j-1;i>0;i--){
			    k=x=i;
			    sum=matrix[i][k]+matrix[k+1][j]+mix[i][k]*mix[k+1][j];
			    k++;
			    //printf("%d  ",sum);
			    for(;k<j;k++){
				    cur=matrix[i][k]+matrix[k+1][j]+mix[i][k]*mix[k+1][j];
				    if(cur<sum){
				        sum=cur;
				        x=k;
				    }
				  // printf("%d  ",cur);     
			    }
			    mix[i][j]=(mix[i][x]+mix[x+1][j])%100;
			    matrix[i][j]=sum;
			    //printf("\n mix[%d][%d]=%d,mix[%d][%d]=%d ",i,x,mix[i][x],x+1,j,mix[x+1][j]);
			   // printf(" mix[%d][%d]= %d matrix[%d][%d]= %d\n",i,j,mix[i][j],i,j,matrix[i][j]);
		    }
	    }
	    printf("%d\n",matrix[1][no]);
	}
	return 0;
}



