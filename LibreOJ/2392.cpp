#include<bits/stdc++.h>
using namespace std;
int n,k,t,x[110000];
bool check(int v){
    for (int i=1;i<=k-1;i++)
        if (2*((k-1)-i)*t*v<x[k-1]-x[i]) return false;
    for (int i=k+1;i<=n;i++)
        if (2*(i-(k+1))*t*v<x[i]-x[k+1]) return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>k>>t;
    for (int i=1;i<=n;i++) cin>>x[i];
    if (x[1]==x[n]){ cout<<"0\n"; return 0;}
    int l=1,r=INF,mid;
    while (l<r){
        mid=(l+r)>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<r<<'\n';
    return 0;
}
