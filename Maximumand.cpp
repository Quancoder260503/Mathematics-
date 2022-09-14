#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+1;
int n;
ll a[sz],b[sz];
bool get_bit(ll val){
    map<ll,ll>mp;
    for(int i=1;i<=n;i++) mp[a[i]&val]++;
    for(int i=1;i<=n;i++) mp[~b[i]&val]--;
    bool t=1;
    for(auto it:mp) t&=(it.second==0);
    return t;
}
void gogo(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    ll ans=0;
    for(int i=29;i>=0;i--){
        if(get_bit(ans|(1ll<<i))){
            ans|=1ll<<i;
        }
    }
    cout<<ans<<endl;
}
int main(){
   int t;cin>>t;
   while(t--){
       gogo();
   }
}

