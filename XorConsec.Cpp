#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 100;
const int INF = 1e7 + 10;
const int mod = 1e9 + 7; 
long long n,m,q,dsz,E;
int timer = 1;
vector<int>adj[N + 1];
int fa[N + 1];
long long d[N + 1];
long long f(long long x){
     if(x % 4 == 0) return x;
     if(x % 4 == 1) return 1;
     if(x % 4 == 2) return x + 1;
     if(x % 4 == 3) return 0;
     return 0;
}
int main(){
     int t; scanf("%d",&t);
     for(int i = 1; i <= t; i++){
         long long l,r; scanf("%lld%lld",&l,&r);
         //cout<<l<<' '<<r<<endl; 
         printf("%lld \n",(f(r) ^ f(l - 1))); 
    } 
}