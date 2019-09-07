// Segment tree with LP by MEET DADHANIA
#include<bits/stdc++.h>
using namespace std;
int build_tree(vector<int> &tree, int i){ // O(n)
  if(tree[i] != -1) return tree[i];
  else{
    tree[i] = min(build_tree(tree, 2*i), build_tree(tree, 2*i+1));
    return tree[i];
  }
}
int min_query(vector<int> &tree, vector<int> &lazy_tree, int i, int li, int ri, int l, int r){ // O(log(n))
  // Handle Lazy updations
  if(lazy_tree[i] > 0){
    cout << i << endl;
    tree[i] += lazy_tree[i];
    lazy_tree[2*i] += lazy_tree[i];
    lazy_tree[2*i+1] += lazy_tree[i];
    lazy_tree[i] = 0;
  }
  // Completely encompasses the range
  if(li>=l && ri<=r) {return tree[i]; cout << i << endl;}
  // No Overlap
  else if(r<li || l>ri) return INT_MAX;
  // Partial Overlap
  else {
    tree[i] = min( 
    min_query(tree, lazy_tree, 2*i, li, (li+ri)/2, l, r),
    min_query(tree, lazy_tree, 2*i+1, (li+ri)/2+1, ri, l, r));
    return tree[i];
  }
}
// Add a number in range
int range_update(vector<int> &tree, vector<int> &lazy_tree, int val, int i, int li, int ri, int l, int r){
  if(li>=l && ri<=r){
    lazy_tree[i] += val;
    return tree[i] += val;
  }
  else if(r<li || l>ri) return INT_MAX;
  else{
    tree[i] = min(
      range_update(tree, lazy_tree, val, 2*i, li, (li+ri)/2, l, r),
      range_update(tree, lazy_tree, val, 2*i+1, (li+ri)/2+1, ri, l, r)
      );
    return tree[i];
  }
}
int main(){
  vector<int> arr = {5, 6, 2, 7, 9, 10, 1};
  int n = arr.size();
  
  // Construction of Tree in TOP-DOWN
  int len = n;
  if(pow(2, (int)log2(n)) != n) len = pow(2,(int)log2(n)+1);
  vector<int> tree(2*len, -1), lazy_tree(2*len, 0);
  for(int i = len, j = 0 ; i < 2*len ; i++, j++)
    if(j >= n) tree[i] = INT_MAX;
    else tree[i] = arr[j];
  build_tree(tree, 1);
  
  return 0;
}