#include "bits/stdc++.h"
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1500000
#define x first 
#define y second
typedef pair<long long,long long> Vec; 
typedef long double ldb;
const int mod = 1e9 + 7; 
long long finv[N];
long long fac[N];
long long inv[N];
long long A[N];  
int n,k;  
signed main(void){
     scanf("%d",&n); 
     for(int i = 0; i < n; i++){
         scanf("%lld",&A[i]); 
     }
     int rank = 0;
     for(int bits = 59; bits >= 0 && rank < n; bits--){
          if(!(A[rank] & (1ll << bits))){
               int cur = -1; 
               for(int i = rank + 1; i < n; i++){
                  if(A[i] & (1ll << bits)){
                      cur = i; 
                      break;  
                  }
               }
               if(cur == -1) continue; 
               A[rank] = A[cur] xor A[rank]; 
          }
          for(int i = 0; i < n; i++){
              if(rank == i) continue;
              if(A[i] & (1ll << bits)){
                   A[i] = A[i] xor A[rank]; 
              }
          }
          rank += 1; 
     }
     long long ans = 0; 
     for(int i = 0; i < n; i++){
         ans = ans xor A[i];
     }
     printf("%lld\n",ans); 
     return 0; 
}