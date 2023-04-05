#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
typedef long long ll;
const int sz = 4e5 + 1;
const int N = 1e6 + 5;
const int M = 1e6 + 5;
const int mod = (1 << 32); 
long long n,m,k,q,x,ans;
long long dp[N + 1]; 
bitset<3002>bit[3002];
int main(){
     cin.sync_with_stdio(0);
     cin.tie(0);
     cin >> n; 
     for(int i = 1; i <= n; i++){
          cin >> bit[i]; 
     }
     for(int i = 1; i <= n; i++){
           for(int j = i + 1; j <= n; j++){
                 int fix = (bit[i] & bit[j]).count();
                 ans += (1ll) * (fix) * (fix - 1);
           }
     }
     cout << (ans >> 1) << '\n'; 
     return 0; 
}