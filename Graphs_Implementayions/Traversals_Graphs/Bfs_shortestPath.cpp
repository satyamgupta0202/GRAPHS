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
        map<T,int>dis;
       
        for(auto node_pair :l){
            T node = node_pair.first;
            dis[node]=INT_MAX;
        }

         q.push(src);
        dis[src]=0;

        while(!q.empty()){
            T node = q.front();
           // cout<<node<<" ";
            q.pop();
            
             for(T nbr : l[node]){
                if(dis[nbr]==INT_MAX){   ///node not visited
                    q.push(nbr);
                    dis[nbr]=dis[node]+1;
                }
            }
        }
        for(auto node_pair: l){
            T node = node_pair.first;
            cout<<"dis of "<<node<<"===" << dis[node]<<endl;
        }
    }


};


int main(){

    graphs<int>g;
    g.insertEdge(0,1);
    g.insertEdge(0,3);
    g.insertEdge(2,3);
    g.insertEdge(3,4);
    g.insertEdge(4,5);
    g.bfs(0);
    return 0;
}