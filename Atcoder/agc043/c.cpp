#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int bas=716070898;//10^18
int n,m,sg[110000],pw[110000],f[4][510]; bool vis[510];
vector<int> vec[110000];
int main(){
	pw[0]=1;
	for (int i=1;i<=100000;i++) pw[i]=1ll*pw[i-1]*bas%Mod;
	
	scanf("%d",&n);
	int T=3;
	while (T--){
		scanf("%d",&m); int u,v;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			vec[min(u,v)].push_back(max(u,v));
		}
		for (int u=n;u>=1;u--){
			for (int v:vec[u]) vis[sg[v]]=true;
			sg[u]=0; while (vis[sg[u]]) sg[u]++;
			for (int v:vec[u]) vis[sg[v]]=false;
		}
		for (int i=1;i<=n;i++){
			f[T][sg[i]]=(f[T][sg[i]]+pw[i])%Mod;
			vec[i].clear();
		}
	}
	int ans=0;
	for (int i=0;i<=450;i++)
		for (int j=0;j<=450;j++)
			if ((i^j)<=450) ans=(ans+1ll*f[0][i]*f[1][j]%Mod*f[2][i^j])%Mod;
	printf("%d\n",ans);
	return 0;
}