// Sieve of Erastosthenes O(loglogn)
// Primes upto n
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n=0;
  cin >> n;
  vector<bool> arr(n+1, true);
  for(int i=2 ; i*i<=n ; i++)
    if(arr[i] == true)
      for(int j=i*i ; j<=n ; j++)
        arr[j] = false;
  for(int i=1 ; i<=n ; i++)
    cout << arr[i] << " ";
  return 0;
} 
