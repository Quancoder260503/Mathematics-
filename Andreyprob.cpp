#include "bits/stdc++.h"
using namespace std; 
#define N 1000005
double A[N]; 
signed main(void)
{
     int n; scanf("%d",&n);
     for(int i = 1; i <= n; i++)
     {
         scanf("%lf",&A[i]); 
     }
     sort(A + 1, A + n + 1);
     reverse(A + 1, A + n + 1); 
     double ans = 0.0; 
     vector<double>stk;
     for(int k = 1; k <= n; k++)
     {
         stk.push_back(A[k]); 
         double tot = 0; 
         for(int i = 0; i < stk.size(); i++)
         {
             double curr = stk[i]; 
             for(int j = 0; j < stk.size(); j++)
             {
                 if(i == j) continue; 
                 curr = curr * (1.0 - stk[j]); 
             }
             tot += curr;
         }
         if(tot < ans)
         {
             stk.pop_back(); 
         }
         else{
             ans = tot;
         }
     }
     printf("%0.14llf\n",ans); 
     return 0; 
}