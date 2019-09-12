// HEAPSORT
#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int n, int i){
  int largest = i;
  int l = 2*i+1, r = 2*i+2;
  if(l < n && arr[l] > arr[largest])
    largest = l;
  if(r < n && arr[r] > arr[largest])
    largest = r;
  if(largest != i){
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
    // cout << arr[i] << " " << arr[largest] << endl; 
  }
}
void heap_sort(vector<int> &arr, int n){
  // Build heap
  for(int i = n-1 ; i >= 0 ; i--)
    heapify(arr, n, i);
  // Sort the heap
  for(int i = n-1 ; i >= 0 ; i--){
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}
int main(){
  int n = 0;
  cin >> n;
  vector<int> arr(n, 0);
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  heap_sort(arr, n); 
  for(int i = 0 ; i < n ; i++)
    cout << arr[i] << " ";
  return 0;
}
