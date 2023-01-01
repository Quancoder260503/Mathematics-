#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
const int N = 1e6+1;
const int mod = 1e9 + 7;
const int inf=1e7+5;
long long ans = 0;
bool prime[N];
long long pw2[sz];
int n,m,k,t;
long long a[N];
long long dp[N];
int main(){
      scanf("%d",&n);
      pw2[0] = 1;
      for(int i = 1; i <= n; i++) pw2[i] = pw2[i - 1]*2;
      for(int i = 1; i <= n; i++){
           int x; scanf("%d",&x); a[x]++;
      }
      long long ans = 0; 
      for(int i = N - 1; i > 1; i--){
            long long val = 0;
            for(int j = i; j < N; j += i) val += a[j];
            if(!val) continue;
            dp[i] = val  * pw2[val - 1] ;
            for(int j = 2 * i; j < N; j += i){
                 dp[i] = (dp[i] - dp[j]); 
            }
            if(dp[i] > 0) cout<<dp[i]<<' '<<i<<endl;
            ans = (ans + dp[i] * i);
      }
      cout<<ans<<endl;
}
