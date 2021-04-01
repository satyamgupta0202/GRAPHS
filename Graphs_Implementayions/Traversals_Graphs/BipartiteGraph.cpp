# include <bits/stdc++.h>
# define ll long long int
using namespace std;
vector<int>adj[10000];   // adjancy List 
int vis[1000];           // visited and color trace
bool bipar=0;            // boolean fuction tp check whether bipartite

void dfs(int node, int par , int color){   
    vis[node]=color;
    for(auto child: adj[node]){
        if(vis[child]==0){
            dfs(child,node,3-color);
        }
        else{
            if(child!=par && color==vis[child]){ // child!=par -> cycle present ... back edge && color is equal represents odd length
                bipar =1;
            }
        }
    }
}



int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0,1);  //child ,parent ,color
    if(bipar){
        cout<<"Graph is not bipartite"<<endl;
    }
    else{
        cout<<"graph is bipartite"<<endl;
    }
    return 0;
}