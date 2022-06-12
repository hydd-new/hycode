#include<bits/stdc++.h>
using namespace std;
int n,m,q,cnt,f[210000],val[210000],sz[210000],fa[19][210000];
int findset(int u){
    if (u!=f[u]) f[u]=findset(f[u]);
    return f[u];
}
int jump(int x,int v){
    for (int i=18;i>=0;i--)
        if (fa[i][x]&&val[fa[i][x]]<=v) x=fa[i][x];
    return x;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) f[i]=i,sz[i]=1;
    int u,v; cnt=n;
    for (int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        u=findset(u); v=findset(v);
        if (u==v) continue;
        cnt++; fa[0][u]=cnt; fa[0][v]=cnt; sz[cnt]=sz[u]+sz[v];
        val[cnt]=i; f[u]=cnt; f[v]=cnt; f[cnt]=cnt;
    }
    for (int j=1;j<=18;j++)
        for (int i=1;i+(1<<j)-1<=cnt;i++)
            fa[j][i]=fa[j-1][fa[j-1][i]];
    scanf("%d",&q); int x,y,k;
    while (q--){
        scanf("%d%d%d",&x,&y,&k);
        int l=0,r=m,mid;
        while (l<r){
            mid=(l+r)>>1;
            u=jump(x,mid); v=jump(y,mid);
            if ((u!=v&&sz[u]+sz[v]>=k)||(u==v&&sz[u]>=k)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",r);
    }
    return 0;
}
