#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
const int sz1=1e6+900000;
const int mod = 1e9 + 7;
const int mod2 = 5e8 + 4; 
const int inf=1e7+5;
long long ans = 0;
bool prime[sz1];
long long pw[sz];
long long n,m,k,t;
long long a[sz];
long long d[sz1];
int main(){
      scanf("%lld%lld",&n,&k);
      vector<long long>divs;
      for(int i = 1; i <= sqrt(n); i++){
           if(n % i == 0){
                if((1ll)* i * i == n) divs.push_back(i);
                else{
                    divs.push_back((1ll)* n / i);
                    divs.push_back(i);
                }
           }
      }
      sort(divs.rbegin(),divs.rend());
      for(int i = 0; i < divs.size(); i++){
          long double LHS = log(divs[i]) + log(k - 1) + log(k + 2) + 0.0000000001; 
          if(LHS < (long double) log(2) + log(n)){
               long long acc = 0;
               for(int j = 1; j < k ; j++){
                    acc += (1ll)*divs[i] * j;
                   cout<<(1ll)*divs[i] * j<<' '; 
               }
               cout<< (1ll) * n - acc<<endl;
               return 0;
          }
      }
      cout<< -1 <<endl;
} 
