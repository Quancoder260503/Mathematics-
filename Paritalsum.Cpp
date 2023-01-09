#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz = 4e5 + 1;
const int N = 1e6 + 1;
const int inf = 1e7+5;
const int mod = 1e9 + 7; 
long long n,m,k,q;
long long b[N];
long long dp[N];
long long a[N];
long long d[N];
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
int main(){
     scanf("%d%d",&n,&k);
     for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
     d[1] = 1;
     for(int i = 2 ; i <= n; i++){
           d[i] = d[i - 1] % mod * (k + i - 2) % mod * binpow(i - 1,mod - 2)% mod; 
     }
     for(int i = 1 ; i <= n; i++){
          for(int j = i; j > 0; j--){
               dp[i] =(dp[i] + d[i - j + 1] % mod * a[j] % mod) % mod;
               ///if(i == j) cout<<dp[i]<<' ';
          }
     }
     for(int i = 1; i <= n; i++) printf("%lld ",dp[i]); 
}
