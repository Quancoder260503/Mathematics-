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
const int mod = 998244353;
long long dp[N];
int ch[26]; 
int timer = 1;
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
      scanf("%d%d",&n,&m);
      binom_init(); 
      long long ans = binom(m,n - 1);
      ans = ans % mod * binpow(2,n - 3) % mod;
      ans = ans % mod * (n - 2) % mod;
      printf("%lld\n",ans); 
      return 0;
}
