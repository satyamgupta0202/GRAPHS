# include <bits/stdc++.h>
using namespace std ; 

class graph{
    
    unordered_map<string, list<pair<int,string>>>l;     // a-> [b 20]
    public:
    
    void addedge(string x,string y ,bool bidir , int d){
        l[x].push_back(make_pair(d,y));
        if(bidir){
          l[y].push_back(make_pair(d,x));
        }
    }

    void print(){
        for(auto p: l){
           string city = p.first;
           list<pair<int,string>> nbrs = p.second;
            
            for(auto child:nbrs){
                int d = child.first;
                string des = child.second;
                cout<<"dis-"<<" "<<d;
                cout<<"destination  "<<des<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){

    graph g;
    g.addedge("a","b",true,20);
    g.addedge("b","d",true,30);
    g.addedge("a","c",true,220);
    g.addedge("c","d",true,201);
    g.addedge("a","d",false,202);
    g.print();
    return 0;
}