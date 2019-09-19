// Kosaraju Algorithm for SCC
#include<bits/stdc++.h>
using namespace std;
void dfs_util(int ind, int n, vector<vector<pair<int, int>>> &graph, stack<int> &s, vector<bool> &visited){
  cout << ind << " ";
  visited[ind] = true;
  for(unsigned int i=0 ; i<graph[ind].size() ; i++)
    if(!visited[graph[ind][i].first])
      dfs_util(graph[ind][i].first, n, graph, s, visited);
  s.push(ind);
  return;
}
void dfs(int ind, int n, int pred, vector<vector<pair<int, int>>> &graph, vector<int> &scc, vector<bool> &visited){
 visited[ind] = true;
 for(unsigned int i=0 ; i<graph[i].size() ; i++){
   if(!visited[graph[ind][i].first]){
    scc[graph[ind][i].first] = ind;
    dfs(graph[ind][i].first, n, pred, graph, scc, visited);
   }
 }
}
vector<int> kosaraju(int n, vector<vector<pair<int, int>>> &graph){
  vector<int> scc(n, 0);
  vector<bool>visited(n, false);
  stack<int> s;
  for(int i=0 ; i<n ; i++)
    if(!visited[i])
      dfs_util(0, n, graph, s, visited);
  // Transpose the graph 
  vector<vector<pair<int, int>>> tgraph(n);
  for(unsigned int i=0 ; i<graph.size() ; i++)
    for(unsigned int j=0 ; j<graph[i].size() ; j++)
      tgraph[graph[i][j].first].push_back(make_pair(i, graph[i][j].second));
  fill(visited.begin(), visited.end(), false);
  while(!s.empty()){
    int top = s.top();
    s.pop();
    dfs(top, n, top, graph, scc, visited);
    cout << endl;
  }
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
