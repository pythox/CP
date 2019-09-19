// Fast Exponentiation O(logn)
#include<bits/stdc++.h>
using namespace std;
int fast_pow(int n, int pow){
  if(pow==1)
    return n;
  else if(pow<1)
    return 1;
  else
    return fast_pow(n*n, pow/2);    
}
int main(){
  long long n=0, power=0, MOD=10e9+7;
  cin >> n >> power;
  if(n%2==1)
    cout << ((n%MOD) * (fast_pow(n, power-1)%MOD)) % MOD;
  else
    cout << fast_pow(n, power)%MOD;
  return 0;
}