#include<bits/stdc++.h>
using namespace std;

class Graph{
  public :
  unordered_map<int,list<pair<int,int>>> adjList;

  void addEdge(int u,int v,int weight,bool direction){
    adjList[u].push_back({v,weight});
    if(direction==0){
      adjList[v].push_back({u,weight});
    }
  }

  void printadj(){
    for(auto nbr :adjList){
      cout<<nbr.first<<"->";
      for(auto it : nbr.second){
        cout<<"{"<<it.first<<","<<it.second<<"}";
      }
      cout<<endl;
    }
  }
  void dijkstra(int src,int dist,int n){
    vector<int> dis(n+1,INT_MAX);
    set<pair<int,int>>st;
    st.insert({0,src});
    dis[src]=0;
    while(!st.empty()){
      auto topelement=st.begin();
      pair<int,int> toppair=*topelement;
      int topdis=toppair.first;
      int topnode=toppair.second;
      st.erase(st.begin());
      for(auto nbr : adjList[topnode]){
        int nbrnode=nbr.first;
        int nbrdis=nbr.second;
        if(nbrdis+topdis<dis[nbrnode]){
          auto previousEntry=st.find({dis[nbrnode],nbrnode});
          if(previousEntry!=st.end()){
            st.erase(previousEntry);
          }
          dis[nbrnode]=nbrdis+topdis;
          st.insert({dis[nbrnode],nbrnode});
        }
      }
    }
    cout<<src<<"->"<<dist<<":"<<dis[dist]<<endl;
  }

};

int main(){
  Graph g;
 g.addEdge(1,6,14,0);
	g.addEdge(1,3,9,0);
	g.addEdge(1,2,7,0);
	g.addEdge(2,3,10,0);
	g.addEdge(2,4,15,0);
	g.addEdge(3,4,11,0);
	g.addEdge(6,3,2,0);
	g.addEdge(6,5,9,0);
	g.addEdge(5,4,6,0);
  g.printadj();
  int n=6;
  g.dijkstra(6,4,6);
  return 0;
}
