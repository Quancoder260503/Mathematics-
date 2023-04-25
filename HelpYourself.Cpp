#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz = 4e5 + 1;
const int N = 1e6 + 10;
const int mod = 1e9 + 7; 
const long long INF = 1e16 + 5;
long long n,m,k,q,p;
vector<int>adj[N + 1];
long long a[N + 1]; 
long long C[N + 1]; 
long long dp[N + 1][26]; 
char s[N + 1]; 
long long binpow(long long a, long long b){
    if(b == 0) return 1;
    long long res = 1;
    while(b > 0){
        if(b & 1) res = res % mod * a % mod;
        a = a % mod * a % mod;
        b >>= 1; 
    }
    return res;
}
signed main(){
      scanf("%d",&n);
      for(int i = 1; i <= n; i++){
           int l,r; 
           scanf("%d%d",&l,&r); 
           C[l] += 1; 
           C[r + 1] -= 1; 
      }
      for(int i = 1; i <= 2 * n; i++){
           C[i] += C[i - 1];
      }
      long long ans = 0;
      for(int i = 1; i <= 2 * n; i++){
           ans = (ans + binpow(2, n - 1 - C[i]) + mod) % mod; 
      }
      ans = (ans + mod) % mod;
      printf("%lld\n",ans); 
      return 0;
}
