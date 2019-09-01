// Union-Find Desjoint Set by MEET DADHANIA
#include<bits/stdc++.h>
using namespace std;
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
int main(){
	int n = 0;
	cin >> n;
	vector<int> arr(n, 0), set(n, 0), rank(n, 0);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];
	for(int i = 0 ; i < n ; i++) set[i] = i;
	return 0;
}