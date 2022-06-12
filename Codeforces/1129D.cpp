#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int INF=0x3f3f3f3f;
int n,k,B,dp[110000],L[110000],R[110000]; vector<int> vec[110000];
int val[110000],tag[110000],bel[110000],sum[110000][350];
void update(int x){
    for (int i=L[x];i<=R[x];i++) val[i]+=tag[x];
    tag[x]=0;
}
void rebuild(int x){
    for (int i=0;i<=B;i++) sum[x][i]=0;
    tag[x]=INF; for (int i=L[x];i<=R[x];i++) tag[x]=min(tag[x],val[i]);
    for (int i=L[x];i<=R[x];i++){
        val[i]-=tag[x];
        sum[x][val[i]]=(sum[x][val[i]]+dp[i-1])%Mod;
    }
    for (int i=1;i<=B;i++) sum[x][i]=(sum[x][i]+sum[x][i-1])%Mod;
}
void add(int l,int r,int v){
    if (l>r) return;
    if (bel[l]==bel[r]){
        update(bel[l]);
        for (int i=l;i<=r;i++) val[i]+=v;
        rebuild(bel[l]);
        return;
    }
    update(bel[l]);
    for (int i=l;i<=R[bel[l]];i++) val[i]+=v;
    rebuild(bel[l]);
    for (int i=bel[l]+1;i<=bel[r]-1;i++) tag[i]+=v;
    update(bel[r]);
    for (int i=L[bel[r]];i<=r;i++) val[i]+=v;
    rebuild(bel[r]);
}
int query(int r){
    int res=0;
    for (int i=1;i<=bel[r]-1;i++)
        if (tag[i]<=k) res=(res+sum[i][min(k-tag[i],B)])%Mod;
	update(bel[r]);
    for (int i=L[bel[r]];i<=r;i++)
        if (val[i]<=k) res=(res+dp[i-1])%Mod;
    rebuild(bel[r]);
    return res;
}
int main(){
    cin>>n>>k; B=sqrt(n+0.5);
    for (int i=1;i<=n;i++){
        bel[i]=(i-1)/B+1;
        if (!L[bel[i]]) L[bel[i]]=i;
        R[bel[i]]=i;
    }
    int x; dp[0]=1;
    for (int i=1;i<=n;i++){
		update(bel[i]); rebuild(bel[i]);
        cin>>x; int v=vec[x].empty()?0:vec[x].back();
        if (vec[x].size()>0) add((vec[x].size()==1?0:vec[x][(int)vec[x].size()-2])+1,v,-1);
        add(v+1,i,1);
        dp[i]=query(i); // cerr<<dp[i]<<'\n';
        vec[x].push_back(i);
    }
    cout<<dp[n]<<'\n';
    return 0;
}
