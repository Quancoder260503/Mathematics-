#include "bits/stdc++.h"
using namespace std;
#define MAXN 1000005
using cd = complex<double>;
const double PI = acos(-1);
int p, k, n, mx_d;
int trs[MAXN];
int cnt[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];
long long ans[MAXN];
vector<long long> currsub;
void fft(vector<cd> &a, int sz, bool invert)
{
    for (int i = 1, mask = 0; i < sz; i++)
    {
        int bit = sz >> 1;
        for (; mask & bit; bit = bit / 2)
        {
            mask = mask xor bit;
        }
        mask = mask xor bit;
        if (i < mask)
        {
            swap(a[i], a[mask]);
        }
    }
    for (int len = 2; len <= sz; len = len * 2)
    {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        cd wang(cos(angle), sin(angle));
        for (int i = 0; i < sz; i += len)
        {
            cd w(1);
            for (int j = 0; j < len / 2; j++)
            {
                cd u = a[i + j];
                cd v = w * a[i + j + len / 2];
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w = w * wang;
            }
        }
    }
    if (invert)
    {
        for (int i = 0; i < sz; i++)
        {
            a[i] /= sz;
        }
    }
    return;
}
vector<long long> mul(vector<long long> &a, vector<long long> &b)
{
    vector<cd> A(a.begin(), a.end()), B(b.begin(), b.end());
    int n = 1;
    while (n < A.size() + B.size())
    {
        n = n * 2;
    }
    A.resize(n);
    B.resize(n);
    fft(A, (int)A.size(), false);
    fft(B, (int)B.size(), false);
    for (int i = 0; i < n; i++)
    {
        A[i] *= B[i];
    }
    fft(A, (int)A.size(), true);
    vector<long long> res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = 1LL * round(A[i].real());
    }
    return res;
}
int dfs(int u, int p)
{
    trs[u] = 1;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v != p and !vis[v])
        {
            trs[u] += dfs(v, u);
        }
    }
    return trs[u];
}
int centroid(int u, int p, int n)
{
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v != p and !vis[v])
        {
            if (trs[v] > n / 2)
            {
                return centroid(v, u, n);
            }
        }
    }
    return u;
}
void path(int u, int p, bool t, int d = 1)
{
    mx_d = max(mx_d, d);
    if (t)
    {
        currsub[d] += 1;
    }
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (vis[v] || v == p)
            continue;
        path(v, u, t, d + 1);
    }
}
void build(int u, int p)
{
    int n = dfs(u, p);
    int c = centroid(u, p, n);
    vis[c] = 1;
    vector<long long>totsub;
    totsub.push_back(1);
    for (int i = 0; i < adj[c].size(); i++)
    {
        int v = adj[c][i];
        if (vis[v])
            continue;
        mx_d = 0;
        path(v, c, 0);
        currsub.resize(mx_d + 1); 
        path(v, c, 1);
        vector<long long> res = mul(totsub, currsub);
        for (int j = 0; j < res.size(); j++)
        {
            ans[j] += res[j];
        }
        while (totsub.size() < mx_d + 1) totsub.push_back(0);
        for (int j = 0; j < currsub.size(); j++)
        {
            totsub[j] += currsub[j];
        }
        while(currsub.size()) currsub.pop_back(); 
    }
    for (int i = 0; i < adj[c].size(); i++)
    {
        int v = adj[c][i];
        if (!vis[v])
            build(v, c);
    }
    return;
}
signed main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        v++;
        u++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    build(1, 0);
    for (int i = 1; i < n; i++)
    {
        printf("%lld ", ans[i]);
    }
    return 0;
}