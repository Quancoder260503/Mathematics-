#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
const int sz1=1e6+900000;
const int mod = 1e9 + 7;
const int inf=1e7+5;
long long ans = 0;
bool prime[sz1];
long long pw[sz];
int n,m,k,t;
long long a[sz];
long long d[sz1];
long long binpow(long long a, long long b){
    if(b == 0) return 1;
    long long res = 1;
    while(b > 0){
        if(b & 1) res = res*a%mod;
        a = a * a % mod;  
        b >>= 1; 
    }
    return res;
}
int main(){
     scanf("%d",&n);
     for(int i = 1; i <= n; i++){  
           scanf("%d%d",&a[i],&pw[i]);
     }
     long long nums = 1;
     long long tots = 1; 
     long long val = 1;
     long long power = 1;
     for(int i = 1; i <= n; i++){
       nums = nums % mod * (pw[i] + 1) % mod; 
       tots = tots*(binpow(a[i],pw[i] + 1)  - 1) % mod * binpow(a[i] - 1 ,mod - 2) % mod;
       val =  binpow(val,pw[i] + 1) % mod*binpow(binpow(a[i],pw[i] * (pw[i] + 1)/2),power) % mod;
       power = power * (pw[i] + 1) % (mod - 1); 
      }
      cout<<nums<<' '<<tots<<' '<<val<<endl;
}