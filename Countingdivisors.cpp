#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;
const int MAXN=1e6;
ll n,k,m,q;
int dp[MAXN+1];
int a[sz];
int divi[MAXN+1];
int treemx[sz<<2];
ll treetot[sz<<2];
int nodiv(int val){
     int x=val;
     int ans=1;
     while(x!=1){
        int c=1;
        int y=divi[x];
        while (x%y==0){
            c++;
            x/=y;
        }
        ans*=c;
     }
     return ans;
}
int main(){
    for(int i=1;i<=n;i++) cin>>a[i];
     for(int i=1;i<=MAXN;i++) divi[i]=i;
     for(int i=2;i*i<=MAXN;i++){
         if(divi[i]==i){
             for(int j=i*i;j<=MAXN;j+=i){
                 if(divi[j]==j) divi[j]=i;
             }
         }
     }
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        cout<<nodiv(x)<<endl;
    }
}