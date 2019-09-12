// DJIKSTRA O(ElogV) using STL set 
#include<bits/stdc++.h>
using namespace std;
vector<int> djikstra(int src, int n, vector<vector<pair<int, int>>> &graph){
  vector<int> pp(n, INT_MAX);
  set<pair<int, int>> s;
  s.insert(make_pair(0, src));
  pp[src] = 0;
  while(!s.empty()){
    pair<int, int> temp = *(s.begin());
    int u = temp.second;
    for(unsigned int i=0 ; i<graph[u].size() ; i++){
      int v = graph[u][i].first, w = graph[u][i].second;
      if(pp[v] > pp[u] + w){
        if(pp[v] != INT_MAX)
          s.erase(s.find(make_pair(pp[v], w)));
        pp[v] = pp[u] + w;
      }
    }
  }
  return pp;
}
int main(){
  int n=0, e=0;
  cin >> n >> e;
  vector<vector<pair<int, int>>> graph(n);
  for(int i=0 ; i<e ; i++){
    int v1, v2, d;
    cin >> v1 >> v2 >> d;
    graph[v1].push_back(make_pair(v2, d));
  }
  vector<int> distance = djikstra(0, n, graph);
  return 0;
}
