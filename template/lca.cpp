// LCA Using binary lifting by MEET DADHANIA
#include<bits/stdc++.h>
using namespace std;
// Preprocess using BFS O(n)
void preprocess(vector<int> &pp, vector<vector<int>> &graph, vector<int> &height, int i, int n){
  vector<bool> visited(n, false);  
  pp[i] = -1;
  queue<int> q;
  q.push(i);
  while(!q.empty()){
    int curr = q.front();
    visited[curr] = true;
    q.pop();
    for(unsigned int i = 0 ; i < graph[curr].size() ; i++){
      if(visited[graph[curr][i]] == false){
        q.push(graph[curr][i]);
        pp[graph[curr][i]] = curr;
        height[graph[curr][i]] = height[curr]+1;
      }
    }  
  } 
}
// Using the dp table return the node at the height h from the start node in O(logn)
int ret_node(int start, int height, vector<vector<int>> dp){
  int sh = ceil(log2(height))+1;
  int curr = start;
  while(height>0){
    if(height>=pow(2, sh)){
      height -= pow(2, sh);
      curr = dp[curr][sh];
    }
    sh--;
  }
  return curr;
}
// Using the ret_node get LCA in O(logn)
int lca(int n1, int n2, vector<vector<int>> &dp, vector<int> &height){
  if(height[n1] > height[n2])
    n1 = ret_node(n1, height[n1]-height[n2], dp);
  else if(height[n2] > height[n1])
    n2 = ret_node(n2, height[n2]-height[n1], dp);
  int sh = floor(log2(height[n1]));
  while(sh > 0){
    if(ret_node(n1, sh, dp) != ret_node(n2, sh, dp)){
      n1 = ret_node(n1, sh, dp);
      n2 = ret_node(n2, sh, dp);
    }
    sh /= 2;
  }
  return ret_node(n1, 1, dp);
}
int main(){
  int n=0, e=0;
  cin >> n >> e;
  vector<vector<int>> graph(n);
  for(int i=0 ; i < e ; i++){
    int s=0, d=0;
    cin >> s >> d;
    graph[s].push_back(d);
    graph[d].push_back(s);
  } 
  int n1=0, n2=0;
  cin >> n1 >> n2; 
  vector<int> pp(n, 0), height(n, 0);
  preprocess(pp, graph, height, 0, n);
  int h = *max_element(height.begin(), height.end());
  h = pow(2, ceil(log2(h)));
  vector<vector<int>> dp(n, vector<int>(h, -1));
  for(int i=1 ; i<n ; i++) dp[i][0] = pp[i];
  for(int i=1 ; i<h ; i++)
    for(int j = 1 ; j < n ; j++)
      if(i <= height[j])
        dp[j][i] = dp[dp[j][i-1]][i-1];
  return 0;
}