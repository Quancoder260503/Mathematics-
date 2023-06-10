#include "bits/stdc++.h"
using namespace std;
#define MAXN 1000005
using cd = complex<double>;
const double PI = acos(-1);
int n, k, m;
void fft(vector<cd> &a, int sz, bool invert)
{
    if (sz == 1)
        return;
    vector<cd> odd(sz / 2), even(sz / 2);
    for (int i = 0; 2 * i < sz; i++)
    {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }
    fft(even, sz / 2, invert);
    fft(odd, sz / 2, invert);
    double angle = 2 * PI / sz * (invert ? -1 : 1);
    cd w(1), wn(cos(angle), sin(angle));
    for (int i = 0; 2 * i < sz; i++)
    {
        a[i] = even[i] + w * odd[i];
        a[i + sz / 2] = even[i] - w * odd[i];
        if (invert)
        {
            a[i] /= 2;
            a[i + sz / 2] /= 2;
        }
        w = w * wn;
    }
}
vector<long long> mul(vector<int> &a, vector<int> &b)
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
signed main(void)
{
    scanf("%d%d%d", &k, &n, &m);
    int x;
    vector<int> A(k + 1);
    vector<int> B(k + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        A[x] += 1;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        B[x] += 1;
    }
    vector<long long> res = mul(A, B);
    for (int i = 2; i < 2 * k + 1; i++)
    {
        printf("%lld ", res[i]);
    }
    return 0;
}