// Kosaraju Algorithm for strongly connected components
#include<bits/stdc++.h>
using namespace std;
void dfs_util(int ind, int n, vector<vector<pair<int, int>>> &graph, stack<int> &s, vector<bool> visited){
  visited[ind] = true;
  for(unsigned int i=0 ; i<graph[ind].size() ; i++)
    if(!visited[graph[ind][i].first])
      dfs_util(graph[ind][i].first, n, graph, s, visited);
  s.push(ind);
}
vector<int> kosaraju(int n, vector<vector<pair<int, int>>> &graph){
  vector<int> scc(n, 0);
  vector<bool>visited(n, false);
  stack<int> s;
  dfs_util(0, n, graph, s, visited);
  // Transpose the graph 
  return scc;
}
int main(){
  int n,e;
  cin >> n >> e;
  vector<vector<pair<int, int>>> graph(n);
  for(int i=0 ; i<e ; i++){
    int v1, v2, w;
    cin >> v1 >> v2 >> w;
    graph[v1].push_back(make_pair(v2, w));
  }
  vector<int> scc = kosaraju(n, graph);
  return 0;
} 
