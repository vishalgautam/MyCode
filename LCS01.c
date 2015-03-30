#include<stdio.h>
#include<string.h>
int main(){
char a[50002],b[50002],*maxsq,*minsq;
int i,j,maxlen,minlen,alen,blen,start,enda,endb,bl=0,count=0,len,col;
int size;
scanf("%s",a);
scanf("%s",b);
alen=strlen(a);
blen=strlen(b);
	for(start=0,enda=alen-1,endb=blen-1;start<enda&&start<endb;){
		if(a[start]==b[start]) {start++;bl=1;}
			else bl=0;
		if(a[enda]==b[endb]){ enda--;endb--;bl=1;count++;}
		if(!bl) break;
	}
	if(alen<blen){
	minlen=enda;maxlen=endb;
	minsq=a;maxsq=b;
	len=alen;
	}	
	else{
	minlen=endb;maxlen=enda;
	minsq=b;maxsq=a;
	len=blen;
	}
	size=len-start-count;
	if(size){
	int me[2][size];
	for(i=start;i<=maxlen;i++){
		len=i-start;
			for(j=start,col=0;j<=minlen;j++,col++){
				if(maxsq[i]==minsq[j]){
					if(len&&col) me[1][col]=me[0][col-1]+1;
						else me[1][col]=1; 
				}
				else {
					if(len&&col) me[1][col]=(me[0][col]>me[1][col-1]?me[0][col]:me[1][col-1]);
					else if(len==0&&col) me[1][col]=me[1][col-1];
					else if(col==0&&len) me[1][col]=me[0][col];
					else me[1][col]=0;
				}
			}
			for(j=0;j<size;j++) me[0][j]=me[1][j];
	}
	printf("%d",me[0][size-1]+start+count);
	}
	else printf("%d",len);
	return 0;
}


