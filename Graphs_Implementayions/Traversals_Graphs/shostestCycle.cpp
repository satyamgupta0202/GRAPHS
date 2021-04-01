#include <bits/stdc++.h>
# define ll long long int
using namespace std;
vector<int>adj[1000];

void bfs(int src , int &ans , int n){
    queue<int>q;
    vector<int>dis(n+1,INT_MAX);
    q.push(src);
    dis[src]=0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto child: adj[node]){
            if(dis[child]==INT_MAX){
                q.push(child);
                dis[child]=dis[node]+1;
            }
            else if(dis[child]>= dis[node]){
                ans = min(ans,dis[child]+dis[node]+1);
            }
        }
    }
}

int main(){

    int n,m,ans=n+1;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    bfs(i,ans,n);

    if(ans==n+1){
        cout<<"No Cycle Dtected"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}