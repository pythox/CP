// BELLMAN FORD O(VE) for directed graphs
#include<bits/stdc++.h>
using namespace std;
vector<int> bellman_ford(int src, vector<vector<pair<int, int>>> &graph, int n){
  vector<int> pp(n, INT_MAX);
  pp[src] = 0;
  for(int dist = 0 ; dist < n-1 ; dist++)
    for(int i=0 ; i < n ; i++)
      for(unsigned int j=0 ; j < graph[i].size() ; j++)
        if(pp[graph[i][j].first] > pp[i] + graph[i][j].second)
          pp[graph[i][j].first] = pp[i] + graph[i][j].second;
  // Check negative cycle
  bool flag = true;
  for(int i=0 ; i<n ; i++)
    for(unsigned int j=0 ; j<graph[i].size() ; j++)
      if(pp[graph[i][j].first] > pp[i] + graph[i][j].second)
        flag = false;
  if(flag == false)
    fill(pp.begin(), pp.end(), -1);
  return pp;
}
int main(){
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n);
  for(unsigned int i=0 ; i < m ; i++){
    int t1=0, t2=0, t3=0;
    cin >> t1 >> t2 >> t3;
    graph[t1].push_back(make_pair(t2, t3));
  } 
  vector<int> distance = bellman_ford(0, graph, n);
  return 0;
}