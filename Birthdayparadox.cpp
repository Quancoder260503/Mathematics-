#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e6 + 3; 
long long power(long long base, long long exp)
{
    long long ans = 1; 
    while(exp)
    {
         if(exp & 1) ans = ans % MOD * base % MOD; 
         exp = exp / 2; 
         base = base % MOD * base % MOD; 
    }
    return ans; 
}
long long modd(long long a, long long mod)
{
     a = a % mod; 
     if(a < 0) a += mod; 
     return a; 
}
signed main(void)
{
    long long n,k; 
    scanf("%lld%lld",&n,&k); 
    if(n <= 63 && k > (1LL << n))
    {
         printf("%d %d\n",1,1); 
         return 0;
    }
    long long s2 = k - 1 - __builtin_popcountll(k - 1); 
    n = modd(n, MOD - 1); 
    long long pk = modd(k, MOD - 1);
    long long exp = 1LL * n * (pk - 1) - s2; 
    exp = modd(exp, MOD - 1);
    long long B = power(2, exp); 
    long long mn = 0;  
    if(k - 1 <= MOD)
    {
        mn = 1; 
        long long tot = power(2,n); 
        mn = power(2, s2);
        mn = power(mn, MOD - 2);
        if(mn < 0) mn += MOD;
        for(int i = 1; i < k; i++)
        {
            mn = mn % MOD * (tot - i) % MOD; 
        }  
    }
    long long A = (B - mn) % MOD; 
    A = modd(A, MOD);
    B = modd(B, MOD); 
    printf("%lld %lld\n",A,B);
    return 0; 
}