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
string s;
void solve(){
    int res=0;
    int n=s.size();
    for(int i=1;i<=n;i++) pos[i]=0;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='0') pos[i]=pos[i-1];
        else pos[i]=i;
    }
    for(int r=1;r<=n;r++){
        int sum=0;
        for(int l=r;l>0 and r-l<20;l--){
            if(s[l-1]=='0') continue;
            sum+=(1<<(r-l));
            if(l==0 and sum<=r) res++;
            if(l>0  and sum<=r-pos[l-1]) res++;
        }
    }
    cout<<res<<endl;
}
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        solve();
    } 
}