// FLOYD WARSHALL O(V^3)
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> floyd_warshall(int n, vector<vector<pair<int, int>>> &graph){
  vector<vector<int>> dp(n,vector<int>(n, INT_MAX)); // Create Adj. matrix from Adj. List
  for(int i=0 ; i<n ; i++) dp[i][i] = 0;
  for(int i=0 ; i<n ; i++)
    for(unsigned int j=0 ; j<graph[i].size() ; j++)
      dp[i][graph[i][j].first] = graph[i][j].second;
  for(int k=0 ; k<n ; k++) // Select every vertex as intermidiate
    for(int i=0 ; i<n ; i++) // Select every vertex as source
      for(int j=0 ; j<n ; j++) // Select every vertex as destination
        if(dp[i][j] > dp[i][k] + dp[k][j])
          dp[i][j] = dp[i][k] + dp[k][j];
  return dp;
}
int main(){
  int n=0, e=0;
  cin >> n >> e;
  vector<vector<pair<int, int>>> graph(n);
  for(int i=0 ; i<e ; i++){
    int v1, v2, w;
    cin >> v1 >> v2 >> w;
    graph[v1].push_back(make_pair(v2, w));
  }
  vector<vector<int>> distance = floyd_warshall(n, graph);
  return 0;
} 
