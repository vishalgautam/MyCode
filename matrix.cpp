#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int main(){
	int row[7],col[7],count=6;
	int matrix[7][7];
	int i=1,sum,j,k,c,cur;
	while(i<=count){
		cin>>row[i]>>col[i];
		i++;
	}
	matrix[1][1]=0;
	for(j=2;j<=count;j++){
		matrix[j][j]=0;
		for(i=j-1;i>0;i--){
			sum=INT_MAX;
			for(k=i;k<j;k++){
				cur=matrix[i][k]+matrix[k+1][j]+row[i]*col[k]*col[j];
				sum=sum>cur?cur:sum;
			}
			matrix[i][j]=sum;
		}
	}
	cout<<matrix[1][count]<<endl;
}



