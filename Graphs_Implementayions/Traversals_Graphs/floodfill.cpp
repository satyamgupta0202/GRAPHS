# include <bits/stdc++.h>
using namespace std;
int r,c;



void colors(char mat[][50] , int a , int b ,char ch , char color){

    if(a<0||b<0||a>=r||b>=c)
    return ;
    if(mat[a][b]!=ch)
    return ;

    int dx[4]= {-1,0,1,0};
    int dy[4]= {0,-1,0,1};

    mat[a][b]=color;
    for(int k=0;k<4;k++){
        colors(mat,dx[k]+a,dy[k]+b,ch,color);
    }
}

int main(){
   char fill[50][50]; 
    int a,b;
    cin>>r>>c;
    cin>>a>>b;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>fill[i][j];
        }
    }
    colors(fill,a,b,'.','*');
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<fill[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}