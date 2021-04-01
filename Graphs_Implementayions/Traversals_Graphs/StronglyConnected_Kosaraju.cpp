//strongly connected components via color

# include <bits/stdc++.h>
using namespace std;
vector<int>a1[1000];  // default 
vector<int>a2[1000]; // reverse edges (KosaRaju Algorithm)
int v1[1000];
int v2[1000];
vector<int>order1;    //ordering of visits
int component[1000];  //which r having same color are in same group

void dfs1(int src){
    v1[src]=1;
    for(auto i:a1[src]){
        if(v1[i]==0){
            dfs1(i);
        }
    }

 order1.push_back(src);     
}

void dfs2(int src,int color){
    v2[src]=1;
   // cout<<src<<" "<<color<<endl;
    component[src]=color;
 
    for(auto i:a2[src]){
        if(v2[i]==0){
            dfs2(i,color);
        }
    }
}


int main(){

    int n,m;
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        a1[x].push_back(y);
        a2[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(v1[i]==0){
            dfs1(i);
        }
    }
    int color=1;
    for(int i=n;i>=1;i--){       // important that we start traveling from last
        if(v2[order1[i]]==0){
            dfs2(order1[i],color);
            color++;
          //  cout<<color<<endl;
        }
    }

    for(int i=1;i<=n;i++){
        cout<<i<<"-----"<<component[i]<<endl;
    }

    return 0;
}