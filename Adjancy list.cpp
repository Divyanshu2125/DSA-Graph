#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
  public:
  unordered_map<int,list<int> > adjlist;

  void addedge(int u,int v,bool direction){
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
        cout<<neighbour<< " ";
      }
      cout<<endl;
    }
  }
};

int main() {
  Graph g;
  g.addedge(0,1,0);
  g.addedge(1,2,0);
  g.addedge(0,2,0);
  cout<<endl;
  g.printadjacencylist();
  return 0;
}
