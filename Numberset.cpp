#include "bits/stdc++.h"
using namespace std;
#define MAXN (int)1e6 + 10
int fa[MAXN];
long long A[MAXN];
map<long long, int> proot;
long long a, b, p;
int comp[MAXN];
bool vis[MAXN]; 
int find(int u)
{
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}
void sieve()
{
    for(int i = 2; i * i < MAXN; i++)
    {
         if(vis[i]) continue; 
         for(int j = 2 * i; j < MAXN; j+= i)
         {
             vis[j] = 1;
         }
    }
}
void solve(int cs)
{
    scanf("%lld%lld%lld", &a, &b, &p);
    int n = b - a + 1;
    long long curr = a;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = p; i <= n; i++)
    {
         if(vis[i]) continue; 
         long long curr = a / i * i;
         if(curr < a) curr += i; 
         for(long long j = curr + i; j <= b; j += i) 
         {
             int u = j - a + 1; 
             int v = curr - a + 1; 
             if(find(u) == find(v)) continue; 
             fa[find(u)] = find(v); 
         }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == i)
            ans += 1;
    }
    printf("Case #%d: %d\n", cs, ans);
    return;
}
signed main(void)
{
    int tc;
    scanf("%d", &tc);
    sieve(); 
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }
    return 0;
}