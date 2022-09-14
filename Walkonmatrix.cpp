#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
ll n,q;
ll timer=1;
vector<ll>adj[sz];
ll col[sz];
ll st[sz],en[sz];
int main(){
    cin>>n;
    cout<<2<<" "<<3<<endl;
    cout<<(ll) (n^(1<<17))<<" "<<(ll)(1<<17) <<" "<<0<<endl;
    cout<<n<<" "<<(ll) ((1<<17)^n)<<" "<<n<<endl;
}