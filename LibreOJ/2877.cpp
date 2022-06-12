#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[110000],tot[110000];
int fa[110000],rk[110000];
int findset(int x){
	if (x!=fa[x]) fa[x]=findset(fa[x]);
	return fa[x];
}
bool Union(int x,int y){
    x=findset(x); y=findset(y);
    if (x!=y){ fa[y]=x; rk[x]+=rk[y]; return true;}
    else return false;
}
void update(int u){
    if (a[u]&&Union(u,a[u])) update(a[u]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m; int u,v;
    for (int i=1;i<=n;i++) fa[i]=i,rk[i]=1;
    for (int i=1;i<=m;i++){
        cin>>u>>v; tot[u]++;
        if (a[u]) Union(a[u],v);
        else a[u]=v;
    }
    for (int i=1;i<=n;i++)
        if (rk[findset(i)]>1&&a[i]) update(i);
    ll ans=0;
    for (int i=1;i<=n;i++)
        if (fa[i]==i) ans+=1ll*rk[i]*(rk[i]-1);
    for (int i=1;i<=n;i++)
        if (a[i]&&findset(i)!=findset(a[i])) ans+=tot[i];
    cout<<ans<<endl;
    return 0;
}
