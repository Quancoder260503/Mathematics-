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
ll l,r,mod,n,q;
ll tree[sz<<2];
int a[sz];
string s;
void update(bool act,ll val,int L,int R,int l=1,int r=1<<n,int p=1){
    if(L>r or R<l) return;
    if(l==r){
        tree[p]=val;
        return;
    }
    int mid=(l+r)>>1;
    update(!act,val,L,R,l,mid,2*p);
    update(!act,val,L,R,mid+1,r,2*p+1);
    if(act) tree[p]=tree[2*p]^tree[2*p+1];
    else tree[p]=tree[2*p]|tree[2*p+1];
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=(1<<n);i++){
        cin>>a[i];
        if(n%2==0) update(1,a[i],i,i);
        else update(0,a[i],i,i);
    }
    for(int i=1;i<=q;i++){
          ll u,v;cin>>u>>v;
          a[u]=v;
          if(n%2==0) update(1,a[u],u,u);
          else update(0,a[u],u,u);
          cout<<tree[1]<<endl;
    }
}