#include<iostream>
#include<list>
#include<climits>
using namespace std;
int size;
int v[10001],ix[10001],mapping[10001];
void heapify(int ind){
    int l=ind*2,r=ind*2+1,key=v[ind];
    int smallest=ind;
    if(l<=size&&key>v[l]){
        smallest=l;
        key=v[l];
    }
    if(r<=size&&key>v[r]){
        smallest=r;
        key=v[r];
    }
    if(smallest!=ind){
        int temp=v[ind];
        v[ind]=key;
        v[smallest]=temp;


        temp=ix[ind];
        ix[ind]=ix[smallest];
        ix[smallest]=temp;

        mapping[ix[ind]]=ind;
        mapping[ix[smallest]]=smallest;
        heapify(smallest);
    }
}
void delmin(){
    v[1]=v[size];
    ix[1]=ix[size];
    mapping[ix[1]]=1;
    size--;
    heapify(1);
}
void heapify_up(int id){
    int p=id/2,temp;
    if(p>=1&&v[p]>v[id]){
        temp=v[p];
        v[p]=v[id];
        v[id]=temp;

        temp=ix[p];
        ix[p]=ix[id];
        ix[id]=temp;

        mapping[ix[p]]=p;
        mapping[ix[id]]=id;
        heapify_up(p);
    }
}

typedef struct node_{
    public:
    int d;
    int wt;
}node;
int main(){
    int n,m,s,t,next_vertex,next_dist;
    int test,dist,x,y,d,k;
    node *temp,*nd;
    int visited[10001];
    int i,vertex,ind;
    std::list<node*> list[10001];
    std::list<node*>::iterator end,it;
    cin>>test;
    while(test--){
        cin>>n>>m>>k>>s>>t;
        //cout<<s<<" "<<t<<endl;
        size=n;
        for(i=1;i<=m;i++){
            cin>>x>>y>>d;
            temp=new node;
            temp->d=y;
            temp->wt=d;
            list[x].push_front(temp);
        }
        for(i=1;i<=k;i++){
            cin>>x>>y>>d;
            temp=new node;
            temp->d=y;
            temp->wt=d;
            list[x].push_front(temp);
            temp=new node;
            temp->d=x;
            temp->wt=d;
            list[y].push_front(temp);
        }
        for(i=1;i<=n;i++){
            v[i]=INT_MAX;
            ix[i]=i;
            mapping[i]=i;
            visited[i]=-1;
        }
        v[s]=0;
        heapify_up(s);
        //cout<<s<<" "<<t<<" "<<v[s]<<" "<<v[1]<<endl;
        while(size){
            vertex=ix[1];
            visited[vertex]=1;
            dist=v[1];
            visited[vertex]=dist;
            if(vertex==t)
                break;
            delmin();
            //cout<<"min "<<vertex<<" "<<dist<<endl;
            end=list[vertex].end();
            for(it=list[vertex].begin();it!=end;it++){
                next_vertex=(*it)->d;
                next_dist=(*it)->wt;
                if(visited[next_vertex]==-1&&v[mapping[next_vertex]]>(dist+next_dist)){
                    v[mapping[next_vertex]]=dist+next_dist;
                   // cout<<"v "<<vertex<<" dest "<<nd->d<<" "<<v[mapping[nd->d]]<<endl;
                    heapify_up(mapping[next_vertex]);
                }
                //else cout<<"s-d "<<vertex<<" "<<nd->d<<" "<<s2t[nd->d]<<endl;
            }
        }
        cout<<visited[t]<<endl;
    }
    return 0;
}


