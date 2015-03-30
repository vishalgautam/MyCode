#include <iostream>
#include <vector>
//#include<cstdio>
 
using namespace std;
 
typedef long long unsigned int ll;
vector<vector<ll> > base;
 
int ady[8][8] = \
{
 {0,1,0,1,1,0,0,0}, // A
 {1,0,1,0,0,1,0,0}, // B
 {0,1,0,1,0,0,1,0}, // C
 {1,0,1,0,0,0,0,1}, // D
 {1,0,0,0,0,1,0,1}, // E
 {0,1,0,0,1,0,1,0}, // F
 {0,0,1,0,0,1,0,1}, // G
 {0,0,0,1,1,0,1,0}, // H
};
ll k,p;
 
vector<vector<ll> > power(vector<vector<ll> > M, ll left) {
        if(left == 0) {
                vector<vector<ll> > r(24,vector<ll>(24,0));
                for(int i = 0; i < 24; i++) r[i][i] = 1;
                return r;
        }
        if(left == 1) {
                return M;
        }
        vector<vector<ll> > r(24,vector<ll>(24,0));
        if(left%2==0) {
                for(int i = 0; i < 24; i++)
                for(int j = 0; j < 24; j++)
                {
                        ll acc = 0;
                        for(int z = 0; z < 24; z++) {
                                acc+=M[i][z]*M[z][j];
                                if(acc>=p) {
                                        acc = acc%p;
                                }
                        }
                        r[i][j] = acc;
                }
                return power(r,left/2);
        } else {
                vector<vector<ll> > r1;
                r1 = power(M,left-1);
                for(int i = 0; i < 24; i++)
                for(int j = 0; j < 24; j++)
                {
                        ll acc = 0;
                        for(int z = 0; z < 24; z++) {
                                acc+=M[i][z]*r1[z][j];
                                if(acc>=p) {
                                        acc = acc%p;
                                }
                        }
                        r[i][j] = acc;
                }
                return r;
        }
}
 
int main () {
        char F, T;
        //scanf(" %c %c  \n", &F, &T);cout<<"vishal";
        cin>>F>>T>>k>>p;
        int from = F-'A', to = T-'A';      
       vector<vector<ll> > matrix(24,vector<ll>(24,0));
        for(int i = 0; i < 8; i++) {
                int pos0 = 0;
                for(int j = 0; j < 8; j++) if(ady[i][j]){
                        int pos1 = 0;
                        for(int z = 0; z < 8; z++) if(ady[j][z]) {
                                if(i==z)
                                        pos1++;
                                else
                                        matrix[i*3+pos0][j*3+pos1++] = 1;
                        }
                        pos0++;
                }
        }
       
        k--;
        matrix = power(matrix, k);
        vector<ll> base(24,0), r(24,0);
 
        for(int j = 0; j < 8; j++) if(ady[from][j]){
                int cnt = 0;
                for(int z = 0; z < from; z++) if(ady[j][z]) cnt++;
                base[j*3+cnt] = 1;
        }
        for(int i = 0; i < 24; i++) {
                ll acc = 0;
                for(int z = 0; z < 24; z++) {
                        acc+=matrix[i][z]*base[z];
                        if(acc>=p) {
                                acc=acc%p;
                        }
                }
                r[i] = acc;
        }
        //printf("%lu\n",
        cout<< (r[to*3]+r[to*3+1]+r[to*3+2])%p;
        return 0;
}
