#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
#define blksz 500
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int sz = 4e5 + 1;
const int N = 1e6 + 10;
const int M = 24;
const int mod = 1e9 + 7;
long long dp[N];
long long A[N]; 
long long D[N]; 
int n,m;
vector<long long>finv;
vector<long long>fac;
vector<long long>inv;
void binom_init() {
    fac.resize(N + 1);
    finv.resize(N + 1);
    inv.resize(N + 1);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for(int i = 2; i < N + 1; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - mod / i * inv[mod % i] % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
long long binom(long long n, long long r){
    if(n < r || n < 0 || r < 0) return 0;
    return (fac[n] * finv[r] % mod * finv[n - r] % mod) % mod;
}
signed main(){
      scanf("%d",&n);
      binom_init();
      int ufix = 0;
      int rfix = 0;
      for(int i = 1; i <= n; i++){
           scanf("%lld",&A[i]);
           if(A[i] == - 1) rfix += 1; 
           else{
                D[A[i]] += 1; 
           }
      }
      for(int i = 1; i <= n; i++){
           if(D[i] && A[i] == -1) ufix += 1; 
      }
      int coef = 1; 
      long long ans = fac[rfix];
      for(int i = 1; i <= rfix - ufix; i++){
           coef = coef * (-1);
           ans = (ans + mod + coef * binom(rfix - ufix, i) % mod * fac[rfix - i] % mod) % mod;
      }
      ans = (ans + mod) % mod; 
      printf("%lld\n",ans); 
      return 0;
}
