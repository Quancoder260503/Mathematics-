#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
ll n,q,l,r;
ll timer=1;
vector<ll>adj[sz];
ll col[sz];
ll st[sz],en[sz];
ll f(ll l , ll r){
    int mxbit=0;
    int bitpos=0;
    if(l==r) return l;
    ll right=r;
    while (right){
        if(right%2==1) mxbit=bitpos;
        right/=2;
        bitpos++;
    }
    ll comp=(1ll<<mxbit);
    ll ans=0;
    if(comp<=l) ans=comp+f(l-comp,r-comp);
    else if(2*comp-1<=r) ans=2*comp-1;
    else ans=comp-1;
    return ans;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        ll x,y; cin>>x>>y;
        ll res=f(x,y);
        cout<<res<<endl;
    }
}