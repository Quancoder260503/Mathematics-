#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1001;
int n;
int a[sz][sz];
int main(){
    cin>>n;
    int add=0;
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            a[i][j]=(add)*4+1;
            a[i][j+n/2]=(add)*4+2;
            a[i+n/2][j]=(add)*4+3;
            a[i+n/2][j+n/2]=(add)*4;
            add++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}