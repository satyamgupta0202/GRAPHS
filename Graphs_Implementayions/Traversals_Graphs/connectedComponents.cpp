# include <bits/stdc++.h>
using namespace std;
template <typename t>
class graph {
    public:
    int count=0;
    map<t,list<t>>l;
    
    void add(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    map<int,int>vis;

    void dfs(int src){
        vis[src]=1;
       // cout<<src<<endl;
        for(auto j:l[src]){
            if(vis[j]==0){
                dfs(j);
            }
        }
    }


    void res(){
    for(auto k : l){
        auto node = k.first;
        if(vis[node]==0){
            count++;
            dfs(node);
        }
    }

     cout<<count<<endl;
    }

};








int main(){
    graph<int>g;
    g.add(1,2);
    g.add(4,5);
    g.add(6,7);
    g.res();
    return 0;
}