#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
const int sz1=1e6+900000;
const int mod = 1e9 + 7;
const int mod2 = 5e8 + 4; 
const int inf=1e7+5;
long long ans = 0;
bool prime[sz1];
long long pw[sz];
long long n,m,k,t;
long long a[sz];
long long d[sz1];
long long binpow(long long a, long long b){
     if(b <= 0) return 1;
     long long res = 1;
     while(b > 0){
          if(b & 1) res = res % mod * a % mod;
          a = a % mod * a % mod;
          b >>= 1;
     }
     return res;
}
int main(){
     scanf("%lld%lld",&k,&n);
     vector<long long>primes;
     long long num = k;
     for(long long i = 2; i * i <= num; i++){
          if(num % i == 0){
             primes.push_back(i); 
             while(num % i == 0) num = num / i; 
          }
     }
     if(num > 1) primes.push_back(num);
     long long ans = 1; 
     for(int i = 0; i < primes.size(); i++){
           long long power = 0;
           long long val = 1;
           while( n / primes[i] >=  val){
                val = val *  primes[i];
                power += n / val;
           }
           ans = ans % mod * binpow(primes[i],power) % mod; 
     }
     cout<<ans<<endl; 
} 
