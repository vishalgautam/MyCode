#include<iostream>
#include<fstream>
using namespace std;
typedef struct point{
    int x,y;
}point;
int main(){
    int T,N;
    int *list;
    cin>>T;
    for(int test=1;test<=T;test++){
        cin>>N;
        list=new point[N+1];
        for(i=0;i<N;i++){
            cin>>point[i].x>>point[i].y;
        }

