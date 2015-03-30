#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int k,len1,len2,i,j,c;
    int mat[1001][1001],len[1001][1001];
    char str1[1001],str2[1001];
    for(i=0;i<=1000;i++){
        mat[i][0]=0;
        len[i][0]=0;
    }
    for(i=0;i<=1000;i++){
        mat[0][i]=0;
        len[0][i]=0;
    }
    while(1){
        cin>>k;
        if(!k){
            break;
        }
        cin>>str1+1>>str2+1;
        len1=strlen(str1+1);
        len2=strlen(str2+1);
        pi=0;pj=0;
        for(i=1;i<=len1;i++){
            for(j=1;j<=len2;j++){
                if(str1[i]==str2[j]){
                    len[i][j]=len[i-1][j-1]+1;
                    c=len[i][j];
                    if(c>=k){
                        if(mat[i-c][j-c]+c>mat[pi+1][pj+1]+j-pj){
                            mat[i][j]=mat[i-c][j-c];
                        }


                    }
                    else {
                        mat[i][j]=std::max(mat[i-1][j],mat[i][j-1]);
                    }
                }
                else {
                    mat[i][j]=std::max(mat[i-1][j],mat[i][j-1]);
                    len[i][j]=0;
                }
            }
        }
        cout<<mat[len1][len2]<<endl;
    }
}


