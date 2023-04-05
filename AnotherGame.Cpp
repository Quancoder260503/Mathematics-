#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int sz = 4e5 + 1;
const int N = 2e5 + 10;
int main(){
     int ntest;
     scanf("%d",&ntest);
     while(ntest--){
          int n; scanf("%d",&n);
          long long ans = 0; 
          for(int i = 0; i < n; i++){
                long long x; scanf("%lld",&x);
                ans |= (x & 1);
          }
          printf(ans ? "first\n" : "second\n"); 
     }
     return 0; 
}