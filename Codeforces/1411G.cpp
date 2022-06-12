#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
void dfs(int u){
	if (vis[u]) return;
	for (int v:vec[u]) dfs(v);
	for (int v:vec[u]) num[sg[v]]=u;
	sg[u]=0;
	while (num[sg[u]]!=u) sg[u]++; 
}
int main(){
	scanf("%d%d",&n,&m); int u,v;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
	}
	for (int i=1;i<=n;i++) dfs(i);
	for (int i=1;i<=n;i++) cnt[sg[i]]++;
	int inv=qpow(n+1,Mod-2);
	for(int i=1,u=Power(n+1,mod-2);i<512;i++){
		f[i][i]=1;
		for(int j=0;j<512;j++)f[i][j]=(f[i][j]-1ll*u*cnt[i^j]%mod+mod)%mod;
	}
	return 0;
}
