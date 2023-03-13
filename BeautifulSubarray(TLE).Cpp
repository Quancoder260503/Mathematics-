#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
typedef long long ll;
#define block 467
typedef pair<int,int> pii;
const int sz = 4e5 + 1;
const int N = 2e5 + 10;
const int M = 1e6 + 10;
const int mod = (1 << 32);
long long n,m,k,q,x;
vector<pii>adj[N + 1];
vector<pair<string,pii>>queries; 
int timer = 0;
long long a[N + 1]; 
struct Node {       
     Node *c[2];
     int cnt; 
};
Node *root = new Node(); 
void insert(Node *node,int x,int bit){
      if(bit < 0){
          node -> cnt++; 
          return;
      }
      if(x & (1 << bit)){
           if(!node -> c[1]) node -> c[1] = new Node();
           insert(node -> c[1],x,bit - 1); 
      }
      else{
           if(!node -> c[0]) node -> c[0] = new Node();
           insert(node -> c[0],x,bit - 1); 
      }
} 
long long query(Node *node, int x,int bit,long long val){
          if(bit < 0) return node -> cnt; 
          long long ans = 0;
          bool on = k & (1 << bit);
          if(x & (1 << bit)){
               ans += node -> c[0] ? query(node -> c[0],x,bit - 1,val + (1 << bit)) : 0;
               if(val >= k or !on) ans += node -> c[1] ? query(node -> c[1],x,bit - 1,val) : 0;
          }
          else{
               ans += node -> c[1] ? query(node -> c[1],x,bit - 1,val + (1 << bit)) : 0;
               if(val >= k or !on) ans += node -> c[0] ? query(node -> c[0],x,bit - 1,val) : 0; 
          }
          return ans; 
} 
int main(){
     scanf("%lld%lld",&n,&k);
     long long ans = 0;
     long long prefix = 0;
     insert(root, prefix,30);
     for(int i = 1; i <= n; i++){
           long long x; scanf("%lld",&x);
           prefix = prefix ^ x; 
           ans += query(root,prefix,30,0); 
           insert(root,prefix,30);
     }
     printf("%lld\n",ans); 
     return 0; 
}
