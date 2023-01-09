#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz = 4e5 + 1;
const int N = 2e6 + 1;
const int mod = 1e9 + 7;
long long n,m,k,q;
long long pows[N + 1];
long long prime[N + 1]; 
long long dp[N + 1];
long long mo[N + 1];
bool vis[N + 1]; 
vector<int>primes[N];
long long binpow(long long a,long long b){
     if(b == 0) return 1;
     long long ans = 1;
     while(b > 0){
         if(b & 1) ans = ans % mod * a % mod;
         a = a % mod * a % mod;
         b >>= 1;
     }
     return ans; 
}
long long inc(int x){
     vector<int>primes;
     int num = x;
     for(int i = 2; i * i <= num; i++){
          if(num % i == 0) primes.push_back(i);
          while(num % i == 0) num = num / i;
     }
     if(num > 1) primes.push_back(num);
     long long ans = 0;
     for(int mask = 1; mask < (1 << primes.size()); mask++){
          bool odd = (__builtin_popcount(mask) & 1); 
          long long product = 1; 
          for(int j = 0; j < primes.size(); j++){
               if((1 << j) & mask){
                     product = (long long) product * primes[j];
               }
          }
          ans += (odd ? 1 : - 1) * (binpow(2, x / product - 1)) % mod;
     }
     ans = ans % mod; 
     return ans;
}
int main(){
     scanf("%d%d",&n,&m);
     if(m % n != 0){
         cout<<0<<endl; 
     }  
     else{
         long long val = m / n; 
         long long ans = (binpow(2, val - 1) - inc(val) + mod) % mod;
         cout<<ans<<endl; 
     }   
}
