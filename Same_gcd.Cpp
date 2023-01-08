#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz = 2e5 + 1;
const int N = 4e4 + 10;
const int mod = 1e9 + 7;
bool primes[301];
long long n,m,k,q,a,b,t;
long long inc(long long y){
      long long num = y;
      vector<long long>primes;
      for(long long i = 2; i * i <= num; i++){
           if(num % i == 0) primes.push_back(i);
           while(num % i == 0) num = num / i;
      }
      if(num > 1) primes.push_back(num);
      long long ans = 0;
      for(int mask = 1; mask < (1 << primes.size()); mask++){
           long long product = 1;
           bool odd = __builtin_popcount(mask) & 1;
           for(int j = 0; j < primes.size(); j++){
                if((1 << j) & mask){
                     product = product * primes[j];
                }
           }
           ans = ans + (odd ? 1 : -1) * ( y / product );
      }
      return y - ans; 
}
int main(){   
      scanf("%d",&t);
      for(int i = 0; i < t; i++){
           long long u,v; scanf("%lld%lld",&u,&v);
           long long res = inc(v / __gcd(u,v));
           cout<<res<<endl;
      }
}
