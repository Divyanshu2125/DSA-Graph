#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>
class Graph{
  public:
  unordered_map<T,list<pair <T,T>> > adjlist;

  void addedge(T u,T v,T weight,bool direction){
    //direction 0 -> undirected edge
    //direction 1 -> directed edge

    adjlist[u].push_back({v,weight});
    if(direction==0){
      adjlist[v].push_back({u,weight});
    }
  }

  void printadjacencylist(){

    for(auto node :adjlist){
      cout<<node.first<<"->";
      for(auto neighbour : node.second){
        cout<<"("<<neighbour.first<< ","<<neighbour.second<<")";
      }
      cout<<endl;
    }
  }
};

int main() {
  Graph<int> g;
  g.addedge(0,1,5,0);
  g.addedge(1,2,6,0);
  g.addedge(0,2,7,0);
  cout<<endl;
  g.printadjacencylist();
  return 0;
}
