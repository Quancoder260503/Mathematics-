#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz = 4e5 + 1;
const int N = 2e6 + 1;
const int mod = 1e9 + 7;
long long n,m,k,q;
long long pows[N + 1];
long long prime[N + 1]; 
long long dp[N + 1];
long long mo[N + 1];
bool vis[N + 1]; 
vector<int>primes[N];
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
void calc(){
     int cnt = 0;
     vis[1] = 1; mo[1] = 1;
     for(int i = 2; i < N; i++){
         if(!vis[i]){ 
            prime[++cnt] = i;
            mo[i] = -1;
         }
         for(int j = 1;  i * prime[j] < N and j <= cnt; j++){
              vis[i * prime[j]] = 1;
              if(i % prime[j] == 0){
                  mo[i * prime[j]] = 0;
                  break; 
              }
              else mo[i * prime[j]] -= mo[i]; 
         }
     }
}
int main(){
     scanf("%d%d",&n,&k);
     long long ans = 0;
     long long tot = 0; 
     calc();
     for(int i = 1; i <= k; i++) pows[i] = binpow(i , n); 
     for(int i = 1; i <= k; i++){
        for(int j = i;  j <= k; j += i){
              dp[j] = (dp[j] + mo[i] * (pows[j / i] - pows[j / i - 1]) + mod) % mod;  
        }
        tot = (tot + dp[i]) % mod ;
        ans = (ans + (tot ^ i)) % mod; 
     } 
     cout<< ans<<endl;
}
