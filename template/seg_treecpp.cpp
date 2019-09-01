// Segment tree by MEET DADHANIA
#include<bits/stdc++.h>
using namespace std;
int build_tree(vector<int> &tree, int i){ // O(n)
	if(tree[i] != -1) return tree[i];
	else{
		tree[i] = min(build_tree(tree, 2*i+1), build_tree(tree, 2*i+2));
		return tree[i];
	}
}
int min_query(vector<int> &tree, int i, int li, int ri, int l, int r){ // O(log(n))
	// Completely encompasses the range
	if(li>=l && ri<=r) return tree[i];
	// No Overlap
	else if(r<li || l>ri) return INT_MAX;
	// Partial Overlap
	else return min( 
		min_query(tree, 2*i+1, li, (li+ri)/2, l, r),
		min_query(tree, 2*i+2, (li+ri)/2+1, ri, l, r));
}
void update(vector<int> &tree, int index, int new_value, int n){ // O(log(n))
	int i = n+index;
	tree[i] = new_value;
	while(i != 0){
		int parent = -1;
		if(i%2==0) parent = i/2-1;
		else parent = i/2;
		if(tree[parent] > tree[i]) tree[parent] = tree[i];
		else break;
		i = parent;
	}
}
int main(){
	vector<int> arr = {5, 6, 2, 7, 9, 10, 1};
	int n = arr.size();
	
	// Construction of Tree in TOP-DOWN
	int len = n;
	if(pow(2, (int)log2(n)) != n) len = pow(2,(int)log2(n)+1);
	vector<int> tree(2*len-1, -1);
	for(int i = len-1, j = 0 ; i < 2*len-1 ; i++, j++)
		if(j >= n) tree[i] = INT_MAX;
		else tree[i] = arr[j];
	build_tree(tree, 0);
	
	return 0;
}