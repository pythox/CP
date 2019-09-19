// Tarjans Algorithm for finding articulation points in a graph
// Conditions : IF ROOT THEN ATLEAST 2 CHILDREN
//              ELSE NO BACKEDGE
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi; 

void dfs_util(int u, int time, vi &disc, vi &low, vi &parent, vi &ap, vi &visited, vvi &graph){
  disc[u] = time;
  low[u] = time;
  visited[u] = 1;
  int children = 0;
  for(unsigned int i=0 ; i<graph[u].size() ; i++){
    int v = graph[u][i];
    if(visited[v]==0){
      children++;
      parent[v] = u;
      dfs_util(v, ++time, disc, low, parent, ap, visited, graph);
      low[u] = min(low[u], low[v]);
      if(parent[u] == INT_MIN && children >= 2)
        ap[u] = 1;
      if(parent[u] != INT_MIN && low[v] >= disc[u])
        ap[u] = 1;
    }
    else if(v != parent[u])
      low[u] = min(low[u], disc[v]);
  }
}

void articulation_points(int n, vector<vector<int>> &graph){
  vi parent(n, INT_MIN), low(n, INT_MAX), disc(n, INT_MAX), visited(n, 0), ap(n, 0);

  for(int i=0 ; i<n ; i++)
    if(visited[i] == 0)
      dfs_util(i, 0, disc, low, parent, ap, visited, graph);
  for(int i=0 ; i<n ; i++)
    cout << ap[i] << " ";
}

int main(){
  int n,e;
  cin >> n >> e;
  vvi graph(n);
  for(int i=0 ; i<e ; i++){
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1); // Undirected Graph
  }
  articulation_points(n, graph);
  return 0;
}