/*
    Link: https://tlx.toki.id/contests/tkoc-2021-day-2/problems/2C
    Created on: 2022/6/12
    Key Observations: 顺序一定是 ↑、↗、→、↘、↓（调整法易证）。

    求出 ↑，↓ 的最小数量。剩下只需要用 ↗，↘ 达到区间最大高度
    ↑、↗ / ↓、↘ 两种对称，只考虑左边，相当于求 a_i-i 的最大值，ST 表维护即可。
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,Q,h[210000],Log2[210000];
struct node{
    int v[20][210000];
    void init(int op){
        for (int i=1;i<=n;i++) v[0][i]=h[i]-i*op;
        for (int j=1;j<=18;j++)
            for (int i=1;i+(1<<j)-1<=n;i++)
                v[j][i]=max(v[j-1][i],v[j-1][i+(1<<(j-1))]);
    }
    int query(int l,int r){
        int k=Log2[r-l+1];
        return max(v[k][l],v[k][r-(1<<k)+1]);
    }
} A,B,C;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Log2[0]=-1;
    for (int i=1;i<=200000;i++) Log2[i]=Log2[i>>1]+1;

    cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    C.init(0);
    A.init(1);
    reverse(h+1,h+n+1);
    B.init(1);
    reverse(h+1,h+n+1);

    cin>>Q; int s,t;
    while (Q--){
        cin>>s>>t;
        if (s==t) cout<<"0\n";
        if (s<t){
            int x=A.query(s,t)+s-h[s];
            int y=B.query(n-t+1,n-s+1)+(n-t+1)-h[t];
            int z=C.query(s,t);
            // cerr<<x<<'#'<<y<<'#'<<z<<'\n';
            cout<<4*x+1*y+2*(t-s)+(z-(h[s]+x))*2-(z-(h[t]+y))*1<<'\n';
        }
        if (s>t){
            swap(s,t);
            int x=A.query(s,t)+s-h[s];
            int y=B.query(n-t+1,n-s+1)+(n-t+1)-h[t];
            int z=C.query(s,t);
            swap(s,t); swap(x,y);
            // cerr<<x<<'#'<<y<<'#'<<z<<'\n';
            cout<<4*x+1*y+2*(s-t)+(z-(h[s]+x))*2-(z-(h[t]+y))*1<<'\n';
        }
    }
    return 0;
}
