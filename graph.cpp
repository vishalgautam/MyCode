#include<iostream>
#include<list>
using namespace std;
class graph{
    int v;
    list<int> *node;
    typedef enum {white=0,grey,black} Color;
    Color *color;
    public:
    typedef list<int>::iterator List;
    graph(int n):v(n){
        color=new Color[v+1];
        node=new list<int>[v+1];
        for(int i=0;i<v;i++)
            color[i]=white;
    }
    void add(int s,int d){
        node[s].push_back(d);
    }
    void dfs(int s);
};
void  graph::dfs(int source){
    int current;
    color[source]=grey;
    List itr=node[source].begin();
    List end=node[source].end();
    while(itr!=end){
        current=*itr++;
        if(color[current]==white)
            dfs(current);
        else if(color[current]==grey)
            cout<<"Cyclic Graph"<<endl;
    }
    color[source]=black;
}
int main(){
    graph gr(6);
    gr.add(1,2);
    gr.add(2,6);
    //gr.add(6,1);
    gr.add(1,3);
    gr.add(3,4);
    gr.add(3,5);
    gr.add(4,6);
    gr.dfs(1);
    return 0;
}
