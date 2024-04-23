#include <bits/stdc++.h>
using namespace std;

class Graph{
  public:
 unordered_map<int,list<int>> adjlist;

 void addedge(int u,int v,bool direction){
  //if direction is 1 then directed graph
  // if direction is 0 then undirected graph
  adjlist[u].push_back(v);

  if(direction==0){
    adjlist[v].push_back(u);
  }
 }
 
 void printAdjanceyLis(){
  for(auto node: adjlist){
    cout<<node.first<<" ->";
    for(auto neighbour : node.second){
      cout<<neighbour<<",";
    }
    cout<<endl;
  }
 }
void bfs(int src){
  queue<int> q;
  unordered_map<int,bool> visited;

  q.push(src);
  visited[src]=true;
  while(!q.empty()){
    int fnode=q.front();
    q.pop();
    cout<<fnode<<",";

    for(auto neighbour : adjlist[fnode]){
      if(!visited[neighbour]){
        q.push(neighbour);
        visited[neighbour]=true;
      }
    }
  }
}

void dfs(int src,unordered_map<int,bool> &visited){
  cout<<src<<",";
  visited[src]=true;
  for(auto neighbour : adjlist[src]){
      if(!visited[neighbour]){
        dfs(neighbour,visited);
      }
  }
}

bool checkCyclicusingbfs(int src,unordered_map<int,bool> &visited){
  queue<int> q;
  unordered_map<int,int> parents;
  q.push(src);
  visited[src]=true;
  parents[src]=-1;
  while(!q.empty()){
    int fnode=q.front();
    q.pop();
    for(auto neighbour : adjlist[fnode]){
      if(!visited[neighbour]){
        q.push(neighbour);
        visited[neighbour]=true;
        parents[neighbour]=fnode;
      }
      else{
        if(neighbour !=parents[fnode]){
          return true;
        }
      }
    }
  }
  return false;
}

};


int main() {
  // unordered_map<int,bool> visited;
  Graph g;
  int n=4;
  g.addedge(0,1,0);
  g.addedge(1,2,0);
  g.addedge(2,3,0);
  g.addedge(3,1,0);
  // g.addedge(4,3,0);
  // g.addedge(3,2,0);
  // g.addedge(3,7,0);
  g.printAdjanceyLis();

  bool ans=false;
  unordered_map<int,bool> visited;

  for(int i=0;i<n;i++){
    if(!visited[i]){
      ans=g.checkCyclicusingbfs(i,visited);
    }
    if(ans==true){
      break;
    }
  }
  if(ans==false){
    cout<<"Graph is not cyclic"<<endl;
  }
  else{
    cout<<"Graph is cyclic"<<endl;
  }

  // cout<<endl;
  // g.bfs(0);
  // cout<<endl;
  // for(int i=0;i<n;i++){
  //   if(!visited[i]){
  //    g.dfs(0,visited);
  //   }
  // }
  
  
  // int n;
  // cin>>n;
  // vector<vector<int>> adj(n,vector<int>(n,0));
  // int e;
  // cin>>e;

  // for(int i=0;i<e;i++){
  //   int u,v;
  //   cin>>u>>v;
  //   adj[u][v]=1;
  // }

  // for(int i=0;i<n;i++){
  //   for(int j=0;j<n;j++){
  //     cout<<adj[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  return 0;
}
