# include <bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
int vis[1000];
int in[1000];
int out[1000];
queue<int>q;
int n;
void bfs(int src)
{    
    q.push(src);
    while(!q.empty()){
        int node =q.front();
        q.pop();
        cout<<node<<endl;
        for(auto it : adj[node]){
            in[it]=in[it]-1;
            if(in[it]==0){
                q.push(it);
            }
        }
    }
}

void res(){
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            bfs(i);
        }
    }
}


int main(){
    int m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        in[y]=in[y]+1;
        out[x]=out[x]+1;
    }
    res();
    return 0;
}