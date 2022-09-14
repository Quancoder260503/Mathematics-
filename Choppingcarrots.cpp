#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+10;
int n,q,m,t,f,x,k;
vector<int>adj[sz];
int a[sz];
int dp[sz];
int pos[sz];
/// This is a tricky problem 
/// However the ideas comes naturally 
/// Since [a[i]/q] can have at most sqrt(a[i]) distinc values
/// Denote the sequence of distinc value in ascending orders
/// Suppose v<=s[1] then max(a[i]/p[i]) has to be at most s[1]
/// s[2]<= v then max(a[i]/p[i]) has to be at least s[2] and so on 
/// For each a[i]-- running j from 1 to min(j,a[k])
/// denote max(a[i]/p[i]) with p[i]<=k and min(a[i]/p[i])>=v is dp[v]
///-->dp[s[j]+1]=max(dp[s[j]+1],s[j+1])
/// Complexity: O(a[1]+nlog(min(a[i],k)) for each cases 
void gogo(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=a[1];i++) pos[i]=0;
    for(int i=1;i<=n;i++){
        int prev=0;
        for(int j=1;j<=min(a[i],k);j=(a[i]/(a[i]/j))+1){
            int md=a[i]/j;
            pos[md+1]=max(pos[md+1],prev);
            prev=md;
        }
        pos[0]=max(prev,pos[0]);
    }
    int cnt=0;
    int ans=1e7+1;
    for(int i=0;i<=a[1];i++){
        cout<<pos[i]<<" ";
        cnt=max(cnt,pos[i]);
        ans=min(ans,cnt-i);
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        gogo();
    }
}