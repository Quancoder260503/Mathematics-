#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
long long n,k;
long long A[N + 1]; 
long long pf[N + 1]; 
long long dp[N + 1][32]; 
signed main(){
     scanf("%d",&n); 
     for(int i = 1; i <= n; i++) scanf("%lld",&A[i]); 
     for(int i = 1; i <= n; i++){
           pf[i] = A[i] xor pf[i - 1]; 
     }  
     long long ans = 0; 
     for(int i = 1; i <= n; i++){
           for(int j = 0; j < 32; j++){
                  dp[i][j] = dp[i - 1][j]; 
                  if(pf[i] & (1ll << j)){
                       dp[i][j] += 1;
                  }
           }
     }
     for(int j = 0; j < 32; j++){
           ans += (1ll) * (1ll << j) * dp[n][j] * (n - dp[n][j]); 
     }
     for(int i = 1; i <= n; i++){
           ans += pf[i];  
     }
     printf("%lld\n",ans); 
     return 0; 
} 
