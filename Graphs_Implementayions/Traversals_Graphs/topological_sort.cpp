# include <bits/stdc++.h>
# define ll long long int
using namespace std;
vector<int>adj[1000];
int vis[1000];
list<int>s;

void dfs(int src){
   vis[src]=1;
    for(auto i: adj[src]){
        if(vis[i]==0){
            dfs(i);
        }
    }
    cout<<src;
    s.push_front(src);  
}

void res(int k){
    for(auto i: adj[k]){

        if(vis[i]==0){
            dfs(i);
        }
    }
}
int main(){

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
     }
     res(1);
     //cout<<s.front();
    return 0;
}