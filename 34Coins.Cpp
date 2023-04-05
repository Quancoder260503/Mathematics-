#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pi;
const int N = 1e7 + 100;
const int INF = 1e7 + 10; 
const int mod = 1e9 + 7;
long long n,U,V;
int timer = 1;
long double dp[N + 1]; 
map<long long,long long>lf,ri; 
pair<long long,long long>a[N + 1]; 
long long f[N + 1];
map<long long,long long>subset(int l,int r){
    int n = r - l + 1;
    map<long long,long long>mp; 
    for(int mask = 0; mask < (1 << n); mask++){
         long long sum = 0; 
         long long cnt = 0; 
         for(int j = l; j <= r; j++){
              if(mask & (1 << (j - l))){
                   cnt++; 
                   sum += f[j]; 
              }
         }
         mp[sum] = max(mp[sum], cnt); 
    }
    return mp;
}
void solve(){
       scanf("%d",&n); 
       long long ans = -INF; 
       for(auto &it : lf){
              if(n < it.first or !ri.count(n - it.first)) continue; 
              ans = max(ans, it.second + ri[n - it.first]);
       }
       if(ans == -INF) printf("%d ", - 1); 
       else printf("%lld ",ans); 
}
int main(){
      f[1] = 2; f[2] = 3; f[3] = 5; 
      for(int i = 4; i <= 34; i++) f[i] = f[i - 1] + f[i - 2] + f[i - 3];
      lf = subset(1 ,17);
      ri = subset(18, 34); 
      int t; scanf("%d",&t);
      int c = 0;
      while(t--){
            c++;
            printf("Case #%d: ",c); 
            solve();
            printf("\n"); 
      }
}