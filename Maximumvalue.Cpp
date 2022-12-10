#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
const int sz1=1e6+1;
const int inf=1e7+5;
int n,m;
long long a[sz1];
long long d[sz1];
int tree[sz<<2];
template<class T> struct Seg {
    const T ID = 0 ;
    T comb(T a,T b){ return max(a,b);}
    int n;vector<int>seg;
    void init(int p){n=p;seg.assign(2*n,ID);}
    void pull(int p){seg[p]=comb(seg[2*p],seg[2*p+1]);}
    void update(int p ,T val){
        seg[p+=n]=val;
        for (p/=2;p;p/=2) pull(p);
    }
    T query(int l,int r){
        T ra=ID;T rb=ID;
        for (l+=n,r+=n+1;l<r;l/=2,r/=2){
            if (l&1) ra=comb(ra,seg[l++]);
            if (r&1) rb=comb(rb,seg[--r]);
        }return comb(ra,rb);
    }
};
Seg<int>seg;
int main(){
      cin>>n;
      int bound = 0;
      for(int i = 1; i <= n; i++){
           int x; cin>>x;
           bound = max(bound,x);
           a[x]++;
           if(a[x]) d[x] = x;
      }
      seg.init(bound + 1);
      for(int i = 1; i <= bound; i++){
           if(a[i]) seg.update(i,i);
      } 
      int ans = 0;
      for(int i = 2; i <= bound; i++){
          if(!a[i]) continue;
          for(int j = i; j <= bound; j += i){
               int lb = (i == j) ? i + 1 : j;
               int rb = min(bound, i + j - 1);
               int mx = seg.query(lb,rb);
               if(mx <= rb) ans = max(mx%i,ans);
          }
      }
      cout<<ans<<endl;
}
