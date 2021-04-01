#include<bits/stdc++.h>

using namespace std;
template <typename T>

class graphs {
    map<T,list<T>>l;
    public:
    void insertEdge(int x, int y){
        l[x].push_back(y);
    }

    void bfs ( T src,T des){
        queue<T>q;
        map<T,int>dis;
        map<T,T>parent;
       
        for(auto node_pair :l){
            T node = node_pair.first;
            dis[node]=INT_MAX;
        }

        q.push(src);
        parent[src]=src;////////
        dis[src]=0;

        while(!q.empty()){
            T node = q.front();
           // cout<<node<<" ";
            q.pop();
            
             for(T nbr : l[node]){
                if(dis[nbr]==INT_MAX){   ///node not visited
                    q.push(nbr);
                    dis[nbr]=dis[node]+1;
                    parent[nbr]=node;
                }
            }
        }
       /* for(auto node_pair: l){
            T node = node_pair.first;
            cout<<"dis of "<<node<<"===" << dis[node]<<endl;
        }*/
        T temp = des;
       
        while(src!=temp){
             cout<<temp<<endl;
             temp = parent[temp];
        }
        cout<<src<<endl;
        cout<<dis[des];
    }
};


int main(){

    graphs<int>g;
    int board[50]={0};
    //if ladders,snakes found then possible jump and drop
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;
   
    for(int i=0;i<=36;i++){
        for(int dice=1;dice<=6;dice++){
            int j=i+dice;
            j+=board[j];
            if(j<=36){
                g.insertEdge(i,j);
            }
        }
    }
    g.insertEdge(36,36);
    g.bfs(0,36);
    return 0;
}