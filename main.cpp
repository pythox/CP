// Kosaraju Algorithm for strongly connected components
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,e;
  cin >> n >> e;
  vector<vector<pair<int, int>>> graph(n);
  for(int i=0 ; i<e ; i++){
    int v1, v2, w;
    cin >> v1 >> v2 >> w;
    graph[v1].push_back(make_pair(v1, w));
  } 
  return 0;
} 
