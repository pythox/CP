// KRUSKAL O(ElogV)
#include<bits/stdc++.h>
using namespace std;

// Boiler-Plate for DSU
int Find(int i, vector<int> &set){
	if(set[i] != i){
		set[i] = Find(set[i], set);
		return set[i];
	}
	else 
		return set[i];
}
void Link(int i, int j, vector<int> &set, vector<int> &rank){
	if(rank[i] > rank[j])
		set[j] = i;
	else if(rank[i] < rank[j])
		set[i] = j;
	else{
		set[j] = i;
		rank[i]++;
	}
}
void Union(int i, int j, vector<int> &set, vector<int> &rank){
	Link(Find(i, set), Find(j, set), set, rank);
}
// ---------------------

vector<pair<int, int>> calc_mst(int n, vector<vector<pair<int, int>>> &graph){
  // Create an edge list from adj. list
  set<pair<int, pair<int, int>>> el;
  vector<pair<int, int>> mst;
	vector<int> set(n, 0), rank(n, 0);
  int count=0;
  for(int i=0 ; i<n ; i++)
    for(unsigned int j=0 ; j<graph[i].size() ; j++)
      el.insert(make_pair(graph[i][j].second, make_pair(i, graph[i][j].first)));
  while(!el.empty() && count!=n-1){
    pair<int, pair<int, int>> temp = *(el.begin());
    el.erase(el.begin());
    int v1 = temp.second.first, v2 = temp.second.second;
    if(Find(v1, set) != Find(v2, set)){
      Union(v1, v2, set, rank);
      mst.push_back(make_pair(v1, v2));
      count++;
    }
  }
  return mst;
}

int main(){
  int n=0, e=0;
  cin >> n >> e;
  vector<vector<pair<int, int>>> graph(n);
  for(int i=0 ; i<e ; i++){
    int v1, v2, w;
    cin >> v1 >> v2 >> w;
    // Only insert at one place for easy handling
    graph[v1].push_back(make_pair(v2, w)); 
  }
  vector<pair<int, int>> mst = calc_mst(n, graph);
  return 0;
} 
