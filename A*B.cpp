#include "bits/stdc++.h"
using namespace std;
#define MAXN (int)1e6 + 10
#define M 50000
using cd = complex<double>;
const double PI = acos(-1);
int n, k, m;
string a, b;
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
    cin >> a >> b;
    vector<int> A(a.length()), B(b.length());
    if (a[0] == '0' || b[0] == '0')
    {
        puts("0");
        return 0;
    }
    for (int i = a.length() - 1; i >= 0; i--)
    {
        A[a.length() - 1 - i] += a[i] - '0';
    }
    for (int i = b.length() - 1; i >= 0; i--)
    {
        B[b.length() - 1 - i] += b[i] - '0';
    }
    vector<long long> res = mul(A, B);
    vector<int> digit(res.size());
    int carry = 0;
    for (int i = 0; i < (int) res.size(); i++)
    {
        digit[i] = (res[i] + carry) % 10;
        carry = (res[i] + carry) / 10;
    }
    int cnt = (int) res.size();
    for (int i = cnt - 1; i >= 0; i--)
    {
        if (digit[i])
        {
            cnt = i + 1;
            break;
        }
    }
    for (int i = cnt - 1; i >= 0; i--)
    {
        printf("%d", digit[i]);
    }
    printf("\n");
    return 0;
}