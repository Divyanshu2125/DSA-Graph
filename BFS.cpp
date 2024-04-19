#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename T>
class Graph{
  public:
  unordered_map<T,list<T> > adjlist;

  void addedge(T u,T v,bool direction){
    //direction 0 -> undirected edge
    //direction 1 -> directed edge

    adjlist[u].push_back(v);
    if(direction==0){
      adjlist[v].push_back(u);
    }
  }

  void printadjacencylist(){

    for(auto node :adjlist){
      cout<<node.first<<"->";
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
      int frontnode=q.front();
      q.pop();
      cout<<frontnode<<" ";
      for(auto neighbour: adjlist[frontnode]){
        if(!visited[neighbour]){
          q.push(neighbour);
          visited[neighbour]=true;
        }
      }
    }
  }

};


int main() {
  Graph<int> g;
  g.addedge(0,1,0);
  g.addedge(1,2,0);
  g.addedge(0,2,0);
  cout<<endl;
  g.printadjacencylist();
  g.bfs(0);
  return 0;
}
