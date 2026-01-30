#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> adjlist;
vector<int> path;
vector<bool> visited;
int v;

bool hasedge(int u,int v){
    for(int x:adjlist[u]){
        if(x==v) return true;
    }
    return false;
}

bool solve(int u,int cnt){
    if(cnt==v){
        return hasedge(u,0);
    }
    for(int x:adjlist[u]){
        if(!visited[x]){
            visited[x]=true;
            path.push_back(x);
            if(solve(x,cnt+1)) return true;
            visited[x]=false;
            path.pop_back();
        }
    }
    return false;
}

int main(){
    v=5;
    adjlist={
        {1,3},
        {0,2,3,4},
        {1,4},
        {0,1,4},
        {1,2,3}
    };
    visited.assign(v,false);
    path.clear();
    path.push_back(0);
    visited[0]=true;
    if(solve(0,1)){
        for(int i:path) cout<<i<<" ";
        cout<<0;
    }
    return 0;
}
