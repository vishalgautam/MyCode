#include<stdio.h>
#include<string.h>
bool map[1000000000]={0};
typedef long long int ULL;
void get(ULL *sum)
{
    char temp;
    long long x=0;
    temp=getchar_unlocked();
    while(temp<48)  temp=getchar_unlocked();
    x+=(temp-'0');
    temp=getchar_unlocked();
    while(temp>=48){
        x=x*10;
        x+=(temp-'0');
        temp=getchar_unlocked();
    }
    *sum=x;

}
int main(){
    ULL step,sum,num,t,temp;
    int digit;

    scanf("%lld",&t);
    while(t--){
        step=0;
        get(&sum);
        //printf("%llu\n",sum);
        while(sum!=1&&map[sum]!=1){
            map[sum]=1;
            num=sum;
            sum=0;
            while(num){
                digit=num%10;
                num/=10;
                sum=sum+digit*digit;
            }
            //printf("%llu ",sum);
            step++;
        }
        if(sum==1){
            printf("%lld\n",step);
        }
        else printf("-1\n");
        memset(map,0,1000000000);
    }
    return 0;
}

