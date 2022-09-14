#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int sz=2e5+1;
typedef long long ll;
int pos[sz];
int t;
ll l,r,mod,n,q;
ll dp[36];
ll tree[sz<<2];
int a[sz];
void solve(){
    ll ans=1;
    for(int i=0;i<30;i++){
        if(n<(1ll<<i)) break;
        ans=ans*(min((1ll<<(i+1))-1,n)-(1ll<<i)+2)%mod;
    }
    ans--;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}
int main(){
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    cin>>t;
    for(int i=0;i<t;i++){
         cin>>n>>mod;
         solve();
    }
    cout<<0<<endl;
}