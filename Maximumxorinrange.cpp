#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
ll n,q,l,r;
ll timer=1;
vector<ll>adj[sz];
ll col[sz];
ll st[sz],en[sz];
ll mxxor(ll l , ll r){
    ll p=(ll) l^r;
    int maxbit=0;
    int bitpos=0;
    while (p){
        if(p%2==1) maxbit=max(bitpos,maxbit);
        p/=2; bitpos++;
    }
    ll ans=0;
    for(int i=0;i<=maxbit;i++) ans+=(1ll<<i);
    return ans;
}
int main(){
    cin>>l>>r;
    ll res=mxxor(l,r);
    if(l==r) cout<<0<<endl; 
    else cout<<res<<endl;
}