#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
const int sz1=1e6+900000;
const int mod = 1e9 + 7;
const int N = 1e4 + 1; 
const int inf=1e7+5;
long long ans = 0;
bool prime[sz];
long long pw[sz];
long long n,m,k,t;
long long a[sz];
long long d[sz1];
long long binpow(long long a, long long b){
     if(b <= 0) return 1;
     long long res = 1;
     while(b > 0){
          if(b & 1){ 
              long double LHS = log(res) + log(a);
              //cout<<res<<' '<<a<<' '<<log(res)<<' '<<log(a)<<' '<<LHS<<endl;
              if(LHS > log(1e18)) return 0; 
              res = (1ll) * res  * a ;
          }
          long double LHS = 2 * log(a);
          b >>=1; 
          if(LHS > log(1e18)) break;
          a = (1ll) * a  * a  ;
     }
     if(!b ) return res;
     else return 0;
}
int main(){
      scanf("%d",&n);
      vector<long long>primes;
      vector<long long> divs;
      int num = n; 
      for(int i = 2; i <= num ; i++){
           while(num % i == 0){
                    divs.push_back(i);
                    num = num / i;
           }
      }
      if(n <= sqrt(1000)){
        for(int i = 1; i <= sqrt(n); i++){
           if(n % i == 0){
                    divs.push_back((1ll)* n / i);
                    divs.push_back(i);
           }
        }
      }
      for(int i = 2; i < N; i++){
          if(prime[i]) continue;
          primes.push_back(i);
          for(int j = 2 * i; j * j < N; j += i) prime[j] = 1;
      }
      long long ans = LLONG_MAX;    
      for(long long mask = 0; mask < (1 << divs.size()); mask++){
           long long product = 1;
           vector<int>elements; 
           for(int j = 0; j < divs.size(); j++){
                if((1 << j) & mask){
                      product = (1ll) * product * divs[j];
                      elements.push_back(divs[j]);
                }                    
           }
           if(product != n) continue;
           sort(elements.rbegin(),elements.rend());
           long long acc = 1;
           for(int i = 0; i < min(primes.size(), elements.size()); i++){
                long long multiply = binpow(primes[i], elements[i] - 1);
                long double LHS = log(acc) + log(multiply);
                if(LHS > log(1e18)){
                    acc = 0;
                    break;
                }
                acc = (1ll) * acc * multiply; 
           }
           if(acc == 0) continue;
           ans = min(ans, acc);
      }
      cout<<ans<<endl;
} 
