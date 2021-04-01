# include <bits/stdc++.h>
using namespace std;
template <typename t>

class graph{
    public:
    map<t,list<t>>l;

    void add(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    map<t,bool>vis;
    bool dfs(int node , int par){
        vis[node]=true;
        for(int child:l[node]){
            if(vis[child]==false){
                return(dfs(child,node));
            }
            if(child!=par){
                return true;
            }
        }
        return false;
    }

};
int main(){
     
     graph<int>g;
     g.add(1,2);
     g.add(2,3);
        g.add(3,1);
     cout<<(g.dfs(1,-1));
    return 0;
}