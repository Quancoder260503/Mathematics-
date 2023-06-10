#include "bits/stdc++.h"
using namespace std; 
signed main(void)
{
     int d,s,e;
     scanf("%d%d%d",&d,&s,&e);
     int re = d - s - e; 
     double ans = 1.0 * s / d; 
     ans = re >= s ? (1.0 - ans) * (1.0 * s / re) : (1.0 - ans) + ans * (1.0 - 1.0 * re / s); 
     printf("%lf\n",ans);
     return 0; 
}