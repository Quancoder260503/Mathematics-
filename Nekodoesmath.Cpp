
 #include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz = 2e5 + 1;
const int N = 4e4 + 10;
const int mod = 1e9 + 7;
bool primes[301];
long long n,m,k,q,a,b;
int main(){
    scanf("%lld%lld",&a,&b);
    if(a > b) swap(a,b);
    vector<long long>div;
    long long x = b - a;
    if(x == 0){
         cout<<0<<endl;
         return 0;
    }
    for(int i = 1; i <= N; i++){
        if(x % i == 0){
             div.push_back(i);
             if(i != x / i) div.push_back(x / i);
        }
    }
    sort(div.begin(),div.end());
    long long ans = LLONG_MAX;
    long long res = INT_MAX;
    for(int i = 0; i < div.size(); i++){
        if(a % div[i] != b % div[i]) continue;
        if(a % div[i] == 0){
             if(ans > a * b / __gcd(a,b)){
                  ans = a * b / __gcd(a,b);
                  res = 0; 
             }
             else if(ans == a * b/__gcd(a,b)) res = 0; 
        }
        else{
             long long pos = div[i] - a % div[i];
             if(ans > (a + pos) * (b + pos) / __gcd(a + pos,b + pos)){
                  ans = (a + pos) * (b + pos) / __gcd(a + pos,b + pos);
                  res = pos;
             }
             else if(ans == (a + pos) * (b + pos) / __gcd(a + pos,b + pos)) res = min(res,pos); 
        }
    }
    cout<<res<<endl;
}
