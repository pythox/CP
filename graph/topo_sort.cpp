// Topological sort O(E+V) 
#include<bits/stdc++.h>
using namespace std;
void util(int ind, vector<bool> &visited, vector<vector<pair<int, int>>> &graph, stack<int> &s){
  for(unsigned int i=0 ; i<graph[ind].size() ; i++)
    if(!visited[graph[ind][i].second])
      util(graph[ind][i].first, visited, graph, s);
  s.push(ind);
}
stack<int> topological_sort(int n, vector<vector<pair<int, int>>> &graph){
  stack<int> s;
  vector<bool> visited;
  for(int i=0 ; i<n ; i++)
    if(!visited[i])
      util(i, visited, graph, s); 
  return s;
}
int main(){
  int n=0, e=0;
  cin >> n >> e;
  vector<vector<pair<int, int>>> graph(n);
  for(int i=0 ; i<e ; i++){
    int n1, n2, w;
    cin >> n1 >> n2 >> w;
    graph[n1].push_back(make_pair(n2, w));
  }
  stack<int> topo_order = topological_sort(n, graph);
  return 0;
} 
