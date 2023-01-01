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
long long pw2[sz];
int n,m,k,t;
long long a[sz1];
long long d[sz1];
int main(){
      scanf("%d",&n);
      n--;
      long long ans = 0;
      for(int i = 1; i <= n; i = 2 * i){
           ans += ((n - i)/(2 * i) + 1) * i;
      }
      cout<<ans<<endl;
}
