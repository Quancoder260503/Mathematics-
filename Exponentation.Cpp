#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz =2e5+10;
const int ssz=5e3+1;
const int mod=1e9+7;
long long p,n,q,timer,m,t;
long long lb,rb; 
queue<int>qe;
int cnt[sz];
int nxt[sz];
int cur[sz];
int a[sz];
long long binpow(long long a, long long b){
    if(b == 0) return 1;
    long long res = 1;
    while(b > 0){
        if(b & 1) res = res%mod*a%mod;
        a = a %mod*a%mod;
        b >>= 1; 
    }
    return res;
}
int main(){
     scanf("%d",&t);
     while(t--){
         int u,v; 
         scanf("%d%d",&u,&v);
         long long ans = binpow(u,v);
         cout<<ans<<endl;
     }
} 