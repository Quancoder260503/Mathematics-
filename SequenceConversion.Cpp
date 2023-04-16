#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
long long n,k;
long long A[N + 1]; 
long long B[N + 1]; 
signed main(){
     scanf("%d",&n); 
     long long xA = 0; 
     long long xB = 0;
     for(int i = 1; i <= n; i++){
         scanf("%lld",&A[i]); 
         xA = xA xor A[i];
     }
     for(int i = 1; i <= n; i++){
         scanf("%lld",&B[i]);
         xB = xB xor B[i]; 
     }
     if(xA != xB){
           printf("%d\n",-1); 
     }
     else{
         long long ans = 0; 
         xA = xB = 0;
         for(int i = 1; i <= n; i++){
              xA = A[i] xor xA;
              xB = B[i] xor xB; 
              ans += (xA != xB); 
         }
         printf("%lld\n",ans); 
     }
     return 0; 
} 
