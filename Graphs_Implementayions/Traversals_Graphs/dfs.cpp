# include <bits/stdc++.h>
using namespace std;
template <typename t>
class graph {
    public:
    map<t,list<t>>l;
    void add(int x , int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    map<t,bool>vis;
/*for(auto i:l){
        auto node = l.first;
        vis[node]=false;
    }*/

    void dfs(int src){
        cout<<src<<endl;
        vis[src] = true;
        for(auto h: l[src]){
            if(vis[h]==false){
                dfs(h);
            }
        }
    }
};

int main(){

    graph<int>g;
    g.add(1,2);
    g.add(2,3);
    g.add(3,4);
    g.add(4,1);
    g.dfs(1);
    return 0;
}