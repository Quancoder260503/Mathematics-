#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz = 4e5+1;
const int N = 1e6+1;
const int inf = 1e7+5;
long long n,m,k,q;
long long b[N];
long long dp[N];
long long a[N];
long long d[N];
vector<int>primes[N];
vector<int>prime;
long long rr = 0;
long long res = 0;
long long inc(int x,int add){
     int num = x;
     if(!primes[x].size()){
        for(int i = 2; i * i <= num; i++){
            if(num % i == 0) primes[x].push_back(i);            
            while(num % i == 0) num = num / i;
        }
        if(num > 1) primes[x].push_back(num);
     }
     long long ans = 0;
     for(int mask = 1; mask < (1 << primes[x].size()); mask++){
          bool odd = (__builtin_popcount(mask) & 1); 
          long long product = 1; 
          for(int j = 0; j < primes[x].size(); j++){
               if((1 << j) & mask){
                     product = (long long) product * primes[x][j];
               }
          }
          if(add == - 1){
              if(!d[product]) continue; 
              ans +=(odd ? 1 : - 1) * (d[product] - 1); 
          }
          else ans += (odd ? 1 : - 1) *(d[product]);
     }
     for(int mask = 1; mask < (1 << primes[x].size()); mask++){
          long long product = 1; 
          for(int j = 0; j < primes[x].size(); j++){
               if((1 << j) & mask){
                     product = (long long) product * primes[x][j];
               }
          }
          d[product] += add; 
    }
    return rr - 1 - ans; 
}
int main(){
      scanf("%d%d",&n,&q);  
      for(int i = 1; i <= n; i++){
          scanf("%d",&a[i]);
      }
      for(int i = 1; i <= q; i++){
           int x; scanf("%d",&x);
           if(b[x]){
                b[x] = 0;
                ///cout<<res<<' '<<rr<<endl; 
                res = res - inc(a[x],-1);
                rr--;
           }
           else{
                b[x] = a[x];
                rr++;
                res = res + inc(a[x],1); 
           }
           cout<<res<<endl;
      }     
}
