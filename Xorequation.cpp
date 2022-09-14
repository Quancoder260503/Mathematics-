#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
ll n,q,l,r;
ll timer=1;
ll f(ll l , ll r){
    int bit=0;
    int bitpos=0;
    int addbit=0;
    if((l-r)%2==1 or (l<r)) return 0;
    ll right=r;  ll left=l;
    bitset<36>sand,sadd;
    ll t=(r-l)/2;
    ll tot=l;
    int maxbit=0;
    while(t){
        sand[bitpos++]=t%2;
        t/=2;
    }
    bitpos=0;
    while(tot){
        if(tot%2==1) maxbit=bitpos;
        sadd[bitpos++]=tot%2;
        tot/=2;
    }
    ll ans=1;
    int cnt=0;
    for(int i=0;i<=maxbit;i++){
        if(sadd[i]==0 and sand[i]==1){
            if(addbit!=0) return 0;
            else addbit=1;
        }  
        if(sadd[i]==1 and sand[i]==0)  {cnt++;if(addbit==0) ans=(ll) ans*2;else addbit=0;}
        if(sadd[i]==1 and sand[i]==1)  if(addbit==0) return 0;
        if(sadd[i]==0 and sand[i]==0)  {cnt++;if(addbit==1) ans=(ll) ans*2;}
    }
     maxbit++;
     if(cnt==maxbit) ans-=2;
     return ans;
}
int main(){
    cin>>l>>r;
    ll res=f(l,r);
    cout<<res<<endl;
} 