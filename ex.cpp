#include<stdio.h>

int main()
{
    FILE *fp=fopen("mdata","r");
    FILE *fw=fopen("mmda","w+");
    char r[100];
    int t,fl;
    while(!feof(fp)) {
        fl=0;
        fscanf(fp,"%s %*s %*s %*s %*s %*s %*s %*s %d %*s %*s",r,&t);
        if(t==0) fl++;
        fscanf(fp,"%s %*s %*s %*s %*s %*s %*s %*s %d %*s %*s",r,&t);
        if(t==0) fl++;
        fscanf(fp,"%s %*s %*s %*s %*s %*s %*s %*s %d %*s %*s",r,&t);
        if(t==0) fl++;
        if(fl==0) fprintf(fw,"%s\n",r);
            }
    return 0;
}
