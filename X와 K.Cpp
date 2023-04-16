#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
long long n,k;
signed main(){
     scanf("%lld%lld",&n,&k); 
     vector<int>bits;
     long long ans = 0;
     for(int i = 0; i < 64; i++){
           if(!((1ll << i) & n)){
                 bits.push_back(i); 
           }
     }
      for(int i = bits.size() - 1; i >= 0; i--){
            if((1ll << i) <= k){
                  ans |= (1ll << bits[i]);
                  k = k - (1ll << i); 
            }
     }
     printf("%lld\n",ans); 
     return 0; 
} 
