#include "bits/stdc++.h"
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1500000
#define MAX 102
#define x first 
#define y second
#define mp make_pair
typedef pair<long long,long long> Vec; 
typedef long double ldb;
const int mod = 1e9 + 7; 
long long X[N];
long long Y[N]; 
int n,k,a,b;  
long double calc(long long *A){
     stack<pair<long long,long long> >stk; 
     double ans = 0; 
     int pos = n; 
     for(int i = 1; i <= n; i++){
         long long upper = A[i];
         long long lower = 1;  
         while(stk.size() && 1ll * stk.top().first * lower >= 1ll * stk.top().second * upper){
               upper += stk.top().first;
               lower += stk.top().second; 
               stk.pop(); 
         }
         stk.push(mp(upper,lower)); 
     }
     while(stk.size()){
          long double x = (long double) stk.top().first / (long double) stk.top().second; 
          int curr = stk.top().second; 
          stk.pop();
          for(int i = 0; i < curr && pos - i >= 0; i++){
               ans += ((long double) A[pos - i] - x) * ((long double) A[pos - i] - x); 
          }
          pos = pos - curr; 
     }
     return ans; 
}
signed main(void){
     scanf("%d",&n); 
     for(int i = 1; i <= n; i++){
          scanf("%lld%lld\n",&X[i],&Y[i]); 
     }
     long double ans = (long double) calc(X) + (long double) calc(Y); 
     printf("%0.15llf\n",ans); 
     return 0; 
}











