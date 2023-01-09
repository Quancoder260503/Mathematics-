#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
const int sz1=1e6+1;
const int inf=1e7+5;
long long n,m,k;
long long a[sz1];
long long d[sz1];
long long inc(int idx,int x){
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
          ans += (odd ? 1 : - 1)*d[product];
     }
     for(int mask = 1; mask < (1 << primes.size()); mask++){
          long long product = 1; 
          for(int j = 0; j < primes.size(); j++){
               if((1 << j) & mask){
                     product = (long long) product * primes[j];
               }
          }
          d[product]++; 
    }
    return idx - ans; 
}
int main(){
      scanf("%d",&n);  
      for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
      long long res = 0;
      for(int i = 1; i <= n; i++){
            res = res + inc(i - 1,a[i]); 
      }
      cout<<res<<endl;
}