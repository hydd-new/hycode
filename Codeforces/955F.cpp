#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int B=19;
int n,cnt,f[310000][21],g[21][310000],dep[310000];
vector<int> vec[310000]; ll ans;
void dfs(int u,int fa){
	for (int v:vec[u]){
		if (v==fa) continue;
		dfs(v,u); dep[u]=max(dep[u],dep[v]);
	}
	dep[u]++;

	cnt=0; ans+=dep[u];
	for (int v:vec[u]){
		if (v==fa) continue;
		cnt++;
		for (int k=1;k<=B;k++) g[k][cnt]=f[v][k];
	}
	f[u][1]=n;
	for (int k=1;k<B;k++){
		sort(g[k]+1,g[k]+cnt+1,greater<int>());
		for (int i=1;i<=cnt;i++)
			if (g[k][i]>=i) f[u][k+1]=i;
	}
}
void dfs2(int u,int fa){
	for (int v:vec[u]){
		if (v==fa) continue;
		dfs2(v,u);
		for (int k=1;k<=B;k++) f[u][k]=max(f[u][k],f[v][k]);
	}
	for (int k=1;k<=B;k++) ans+=max(f[u][k]-1,0);
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1,0); dfs2(1,0);
	printf("%lld\n",ans);
	return 0;
}
