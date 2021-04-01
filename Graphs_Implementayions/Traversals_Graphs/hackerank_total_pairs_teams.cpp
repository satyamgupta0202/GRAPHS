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
    map<int ,int>vis;
    int c=0;
    void dfs(int src){
        vis[src]=1;
        c++;
        for(auto k : l[src]){
            if(vis[k]==0){
                dfs(k);
            }
        }
    }
    void res(){
        auto ans =1;
        for(auto i: l){
            auto node = i.first;
            if(vis[node]==0){
                c=0;
                dfs(node);
                 ans=ans*c;
            }  
        }
        cout<<ans;   
    }
};


int main(){
graph<int>g;
g.add(1,2);
g.add(4,5);
g.res();
return 0;
}
