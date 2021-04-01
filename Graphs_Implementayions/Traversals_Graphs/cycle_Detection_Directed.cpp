# include <bits/stdc++.h>
# include<stack>
using namespace std;
vector<int>adj[1000];
int vis[1000];
map<int,bool>s;
bool cycle=false;
int n,m;
bool dfs(int src){
    vis[src]=1;
    s[src]=true;
    
    for(int i : adj[src]){
            if(s[i]==true){
                return true; 
            }
        else if(vis[i]==0){
            cycle = dfs(i); 
            if(cycle==true)
            return true;
        }
        else{
            s[i]=false;
        }
        }
        s[src]=false;
        return false;
    }
    
    bool res(){
        for(int i=1;i<=m;i++){
            if(dfs(i))
            return true;
        }
        return false;
    }
int main(){
   // int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    bool ans = res();
    if(ans){
        cout<<"Cycle is Present"<<endl;
    }
    else{
        cout<<"Cycle is not Present"<<endl;
    }
    return 0;
}