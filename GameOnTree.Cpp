#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include<vector>
using namespace std;
const int N = 5e5 + 1;
long long pf[N + 1];
vector<int>adj[N + 1]; 
int n;
double ans;
void dfs(int u,int p,double d){
     ans += 1.0 / d;
     for(int i = 0; i < adj[u].size(); i++){
          int v = adj[u][i];
          if(v == p) continue;
          dfs(v,u,d + 1.0); 
     }
}
int main(){
      scanf("%d",&n);
      for(int i = 0; i < n - 1; i++){
           int u,v; scanf("%d%d",&u,&v);
           adj[u].push_back(v);
           adj[v].push_back(u); 
      }
      dfs(1,0,1.0);
      printf("%.15lf\n",ans); 
      return 0;
}
