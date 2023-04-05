#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int sz=2e5+1;
typedef long long ll;
ll l,r,mod,n,q;
int cnt;
multiset<ll>s;
bool t=1;
template<class T> struct Trie {
	struct Node { 
        int cntl=0;
        int cntr=0;
		int l = -1, r = -1; 
	};
	int B;
    int t;
	vector<Node> nodes;
	int newNode() { 
		nodes.emplace_back();
		return nodes.size() - 1;
	}
 
	void init(int _B) {
		B = _B;
		nodes.clear();
		newNode();
	}
 
	void insert(int n) {
		int u = 0;
		for (int i = B; i >= 0; i--) {
			if ((n >> i) & 1) {
				if (nodes[u].r == -1) {
					nodes[u].r = newNode(); 
				}
                nodes[u].cntr++;
				u = nodes[u].r;
			} else {
				if (nodes[u].l == -1) {
					nodes[u].l = newNode();
                }
                nodes[u].cntl++;
				u = nodes[u].l;
			}
		} 
	}
    void erase(int n){
       int u=0;
        for(int i=30 ; i>=0 ;i--) {
            if( ( n >> i ) & 1 ){
              if(nodes[u].r != - 1){
                int pos=nodes[u].r;
                if(nodes[u].cntr > 0) nodes[u].cntr--;
                if(nodes[u].cntr== 0 ) nodes[u].r=-1;
                u=pos;
              }
            }
            else{
                if( nodes[u].l!=-1 ){
                    int pos=nodes[u].l;
                    if(nodes[u].cntl  > 0) nodes[u].cntl--;
                    if(nodes[u].cntl == 0 ) nodes[u].l=-1;
                    u=pos;
                }
            }
        }
    }
	ll query(int n) {
		int u = 0; 
        ll ans = 0;
		for (int i = B; i >= 0; i--) {
			if ((n >> i) & 1) {
				if (nodes[u].r != -1) {
					          u = nodes[u].r;
                    ans += (1ll << i);
				} else {
					   u = nodes[u].l;
				}
			} else {
				 if (nodes[u].l != -1 ) {
					    u = nodes[u].l;
				} else {
					   u = nodes[u].r;
             ans += (1 << i); 
				}
			}
		}
		return ans;
	}
};
Trie<int>trie;
int main(){
    cin>>n;
    trie.init(30);
    //trie.insert(0);
    multiset<int>s;
    for(int i=1;i<=n;i++){
        int t,v; cin>>t>>v;
        if(t == 0){
            s.insert(v); 
            trie.insert(v);
        }
        else if(t == 1){
            auto it = find(s.begin(),s.end(),v);
            if(it == s.end()) continue;
            s.erase(*it); 
            trie.erase(v);
        }
        else if(t == 2){
           ll res = (trie.query(v) ^ v);
           cout<<res<<endl; 
          // scanf("%lld \n",res); 
        }
    }
}