#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz = 2e5 + 1;
const int N = 4e4 + 10;
const int mod = 1e9 + 7;
bool primes[301];
long long n,point,d,w;
long long gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (1LL) * y1 * (a / b);
    return d;
}
int main(){   
      scanf("%lld%lld%lld%lld",&n,&point,&w,&d);
      long long x,y;
      long long dis = gcd(w,d,x,y);
      if(point == 0){
           cout<<0<<' '<<0<<' '<<n<<endl;
           return 0;
      }
      if(point % dis == 0){
          long long a = point / dis;
          long long b = w / dis;
          y = ( (1ll) * ((y % b)* (a % b)) % b + b) % b;
          x = (point - y * d) / w; 
         if(x >= 0 and y >= 0 and x + y <= n){
              cout<<x<<' '<<y<<' '<<n - x - y <<endl;
              return 0;
         }
      }
      cout<<-1<<endl;
}
