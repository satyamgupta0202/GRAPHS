# include<bits/stdc++.h>
# define ll long long int
using namespace std;

template <typename T>

class graphs {

    map<T,list<T>>l;

    public:
    void insertEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs ( T src){
        queue<T>q;
        map<T,int>vis;

        q.push(src);
        vis[src]=true;

        while(!q.empty()){
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            
             for(int nbr : l[node]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr]=true;
                }
            }
        }
    }


};


int main(){

    graphs<int>g;
    g.insertEdge(0,1);
    g.insertEdge(1,2);
    g.insertEdge(2,3);
    g.insertEdge(3,4);
    g.bfs(0);
    return 0;
}