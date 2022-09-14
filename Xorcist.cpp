#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int sz=2e5+1;
typedef long long ll;
int pos[sz];
int t;
ll l,r;
string s;
void solve(){
    cin>>l>>r;
    int maxbit=0;
    ll x=(r-l)/2;
    if(l==r and r==0){
        cout<<0<<endl;
        return;
    }
    if(l==r){
        cout<<1<<endl;
        cout<<l<<endl;
        return;
    }
    if((r-l)%2==1 or l>r){
        cout<<-1<<endl;
        return;
    }
    bitset<36>sand;
    bitset<36>xr;
    ll lf=l; ll ri=x;
    int bitpos=0;
    while(lf){
       if(lf%2==1) maxbit=max(maxbit,bitpos);
       xr[bitpos++]=lf%2;
       lf/=2;
    }
    bitpos=0;
    while(ri){
        if(ri%2==1) maxbit=max(maxbit,bitpos);
        sand[bitpos++]=ri%2;
        ri/=2;
    }
    for(int i=0;i<=maxbit;i++){
        if(xr[i]==1 and sand[i]==1){
            cout<<3<<endl;
            cout<<l<<" "<<x<<" "<<x<<endl;
            return;
        }
    }
    cout<<2<<endl;
    cout<<x+l<<" "<<x<<endl;
    return;
}
int main(){
    cin>>l>>r;
    solve();
    
}