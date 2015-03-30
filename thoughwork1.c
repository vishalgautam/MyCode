#include<stdio.h>
#include<string.h>
int main(){
    int tc,i,vowel;
    scanf("%d",&tc);
    char brow[3],vow[26],c='a';
    memset(vow,0,26);
    vow[0]=1;vow['e'-c]=1;vow['i'-c]=1;
    vow['o'-c]=1;vow['u'-c]=1;
    getchar();
    while(tc--){
        i=0;vowel=0;getchar();getchar();getchar();getchar();
        while(1){
            scanf("%c",&c);
            if(c=='.') break;
            if(vow[c-'a']==1){
                vowel++;
            }
            i++;
        }
        getchar();getchar();getchar();getchar();
        printf("%d/%d\n",(i-vowel)+4,i+8);
    }
    return 0;
}


