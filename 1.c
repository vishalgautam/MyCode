#include<stdio.h>
#include<string.h>
int main(){
	
	int test,num,k,p,prime[1000001];
	long long res;
	//int pt[1000000];
	//memset(pt,1,1000000*sizeof(int));
	memset(prime,0,1000001*sizeof(int));
	//pt[0]=0;
	prime[1]=prime[0]=1;
	for(p=2;p<=1000;p++){
		if(!prime[p]){
			prime[p]=p;
			for(k=2;k*p<=1000000;k++){
				prime[k*p]=p;
				//pt[k*p]=0;
			}
		}
	}
	scanf("%d",&test); 
	while(test--){
		scanf("%d",&num); 
			res=1;
			//if(pt[num]) printf("%d\n",num-1);
			//else{
			while(num>1){
				p=prime[num];
				if(p==0) {res*=(num-1); break;}
				k=1;
				for(;num%p==0;k*=p,num/=p);
				res*=((k/p)*(p-1));
			}
			printf("%llu\n",res);
	}
}
