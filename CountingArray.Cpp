#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz = 4e5 + 1;
const int N = 1e6 + 100;
const int inf = 1e7+5;
const int mod = 1e9 + 7; 
long long n,m,k,q;
long long b[N];
long long dp[N];
long long a[N];
long long d[N];
long long fac[N + 100];
long long inv[N + 100];
long long finv[N + 100]; 
long long binpow(long long a,long long b){
     if(b == 0) return 1; 
     long long ans = 1; 
     while(b > 0){
           if(b & 1) ans = ans % mod * a % mod;
           a = a % mod * a % mod;
           b >>= 1;
     }
     return ans; 
}
void binom_init() {
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for(int i = 2; i < N + 1; i++){
        fac[i] = fac[i - 1] % mod * i % mod;
        inv[i] = mod - mod / i  % mod * inv[mod % i] % mod;
        finv[i] = ((finv[i - 1] % mod) % mod) % mod * ((inv[i] % mod) % mod)% mod;
    }
}
long long binom(long long r, long long n){
    if( n < r || n < 0 || r < 0) return 0;
    return (fac[n] * finv[r] % mod * finv[n - r] % mod) % mod;
}
int main(){
     int t;
     scanf("%d",&t);
     binom_init(); 
     long long cnt = 0; 
     for(int j = 0; j < t; j++){       
         int y,x; scanf("%d%d",&x,&y);
         if(j == 0) cnt = x;
         vector<int>pows; 
         ////if(cnt == 253051 and j == 61024 and t == 100000) cout<<y<<' '<<y<<endl;
         for(int i = 2; i * i <= x; i++){
              int count = 0;
              while(x % i == 0){
                  count++;
                  x = x / i; 
              }
              if(!count) continue;   
              pows.push_back(count);
         }
         if(x > 1) pows.push_back(1);
         long long ans = 1;
         for(int i = 0; i < pows.size(); i++){
              //cout<<pows[i]<<endl;
              ans = ans % mod * binom(pows[i], y + pows[i] - 1) % mod;
         }
         ans = ans % mod * binpow(2,y - 1) % mod; 
         cout<<ans<<endl;
     }
}
