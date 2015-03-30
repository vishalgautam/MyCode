#include<stdio.h>
#include<string.h>
int main(){
  int col,len,i,j,b=0,row,k;
  char a[250];
  while(1){
    scanf("%d",&col);b=k=0;
    if(col==0) break;
    scanf("%s",a);
    len=strlen(a);
    row=len/col;
    char t[row][col];
    for(i=0;i<row;i++)
    {
      if(b=!b)
      {
	for(j=0;j<col;j++)
	  t[i][j]=a[k++];
      }
      else
      {
	for(j=col-1;j>=0;j--)
	  t[i][j]=a[k++];
      }
    }
    
     for(i=0;i<col;i++)
       for(j=0;j<row;j++)
	 printf("%c",t[j][i]);
       printf("\n");
  }
  return 0;
}
    
    