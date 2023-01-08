
 #include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz = 2e5 + 1;
const int N = 1e8 + 50;
const int mod = 1e9 + 7;
bool primes[301];
long long n,m,k,q;
int main(){
     long long a,b;
     scanf("%lld%lld",&a,&b);
     long long x = a + b;
     long long ans = LLONG_MAX;
     for(long long  i = (1ll) * sqrt(x); i > 0; i--){
          if(x % i == 0){
               long long r = i; 
               long long d = x / i;
               for(long long j = r ; j > 0; j--){
                    if(a % j == 0 and a / j <= d or b % j == 0 and b / j <= d){
                        // cout<<r<<' '<<d<<endl;
                         cout<<((r + d) * 2);
                         return 0;
                    }
               }
          }
     } 
}
