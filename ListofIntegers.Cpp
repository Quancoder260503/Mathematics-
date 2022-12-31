#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
const int sz1=1e6+900000;
const int inf=1e7+5;
bool prime[sz1];
int n,m,k,t;
long long a[sz1];
long long d[sz1];
vector<int>primes[sz1];
long long inc(int val,int x){
     long long ans = 0;
     for(int mask = 1; mask < (1 << primes[x].size()); mask++){
          bool odd = (__builtin_popcount(mask) & 1); 
          long long product = 1; 
          for(int j = 0; j < primes[x].size(); j++){
               if((1 << j) & mask){
                     product = (long long) product * primes[x][j];
               }
          }
          if(product > val) continue;
          ans += (odd ? 1 : - 1)*(val / product);
     }
     return val - ans; 
}
bool check(int d,int p,int x,int dis){
     return inc(d,p) >= dis + inc(x,p);
}
int solve(int p,int x,int k){
      int high = 1e7 + 1;
      int low = 0; 
      while(low < high){
                int mid = low + (high - low)/2; 
                if(check(mid,p,x,k)) high = mid;
                else low = mid + 1;
      }
      return low;
}
struct query{
     int x,p,k;
} val[sz];
int main(){
      scanf("%d",&t);
      int MAXN = sz1;
      vector<int>store;
      for(int i = 0; i < t; i++){
           int x,p,k;
           scanf("%d%d%d",&val[i].x,&val[i].p,&val[i].k);
      }  
      for(int i = 0; i < t; i++){ 
           int num = val[i].p;
           if(primes[num].size() > 0) continue;
           for(int j = 2; j * j <= num; j++){
               if(num % j == 0) primes[val[i].p].push_back(j);
               while(num % j == 0) num = num / j;
           }
           if(num > 1) primes[val[i].p].push_back(num);
      }
      for(int i = 0; i < t; i++){
           int ans = solve(val[i].p,val[i].x,val[i].k); 
           cout<<ans<<endl; 
      }
}
