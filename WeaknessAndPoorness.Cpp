#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N = 5e5 + 10;
#define double long double
const long long INF = 1e14 + 1;
typedef pair<int,int> pii;
int n,q,k,m,s,t;
const double eps = 3e-14; 
double a[N + 1]; 
double f(double x){
      double sum = 0;
      double ans = 0;
      for(int i = 1; i <= n; i++){
            sum += (a[i] - x); 
            ans = max(ans, sum);
            if(sum <= 0) sum = 0; 
      }
      sum = 0;
      for(int i = 1; i <= n; i++){
            sum += (x - a[i]);
            ans = max(ans, sum); 
            if(sum < 0) sum = 0; 
      }
      return ans; 
}
signed main(){
      scanf("%d",&n); 
      double l = 10000; 
      double r = -10000; 
      for(int i = 1; i <= n; i++){ 
          cin >> a[i];
          l = min(a[i], l);
          r = max(a[i], r); 
      }
      while(r - l >= eps){
            double x1 = l + (r - l) / 3; 
            double x2 = r - (r - l) / 3;
            if(f(x1) < f(x2)) r = x2; 
            else l = x1; 
      }
      cout << setprecision(15) << f(l) << endl; 
      return 0;
}