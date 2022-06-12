#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n,q,a[310000];
int dep[310000],fa[20][310000];
ull p[310000]; bool fw;
vector<int> vec[310000];
struct node{
    int cnt,ls[12100000],rs[12100000];
    ull val[12100000];
    void change(int &u,int v,int l,int r,int x){
        u=++cnt;
		ls[u]=ls[v]; rs[u]=rs[v]; val[u]=val[v]^p[x];
        if (l==r) return;
        int mid=(l+r)>>1;
        if (x<=mid) change(ls[u],ls[v],l,mid,x);
        else change(rs[u],rs[v],mid+1,r,x);
    }
    int query(int u,int v,int l,int r,int x,int y,int t){
        if (x<=l&&r<=y&&val[u]==val[v]) return -1;
        if (l==r){
            if (l==t){
				fw=true;
				return -1;
			}
            return l;
        }
        int mid=(l+r)>>1,res=-1;
        if (x<=mid){
            res=query(ls[u],ls[v],l,mid,x,y,t);
            if (res!=-1) return res;
        }
        if (y>mid){
            res=query(rs[u],rs[v],mid+1,r,x,y,t);
            if (res!=-1) return res;
        }
        return -1;
    }
} T; int rt[310000];
void dfs(int u,int f){
    fa[0][u]=f; dep[u]=dep[f]+1;
    for (int i=1;i<=18;i++) fa[i][u]=fa[i-1][fa[i-1][u]];
    T.change(rt[u],rt[f],1,n,a[u]);
    for (int v:vec[u]){
        if (v==f) continue;
        dfs(v,u);
    }
}
int LCA(int u,int v){
    if (dep[u]<dep[v]) swap(u,v);
    int d=dep[u]-dep[v];
    for (int i=0;i<=18;i++)
        if (d&(1<<i)) u=fa[i][u];
    if (u==v) return u;
    for (int i=18;i>=0;i--)
        if (fa[i][u]!=fa[i][v]){
            u=fa[i][u];
            v=fa[i][v];
        }
    return fa[0][u];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    mt19937_64 s(chrono::system_clock::now().time_since_epoch().count());

    cin>>n>>q; int u,v;
    for (int i=1;i<=n;i++) cin>>a[i],p[i]=s();
    for (int i=1;i<n;i++){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1,0); int l,r,w;
    while (q--){
        cin>>u>>v>>l>>r; w=LCA(u,v); fw=false;
        int res=T.query(rt[u],rt[v],1,n,l,r,a[w]);
        if (res!=-1) cout<<res<<'\n';
        else if (!fw&&l<=a[w]&&a[w]<=r) cout<<a[w]<<'\n';
        else cout<<"-1\n";
    }
    return 0;
}
