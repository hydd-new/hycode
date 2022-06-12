#include<bits/stdc++.h>
using namespace std;
int n,m,q,fa[3100],sz[3100],s[21000],t[21000]; vector<int> vec[3100];
bool connect[3100][3100],vis[3100],flag[21000][3100];
int edgenum1,vet1[41000],Next1[41000],Head1[41000];
int edgenum2,vet2[41000],Next2[41000],Head2[41000];
void addedge1(int u,int v){
	vet1[++edgenum1]=v;
	Next1[edgenum1]=Head1[u];
	Head1[u]=edgenum1;
}
void addedge2(int u,int v){
	vet2[++edgenum2]=v;
	Next2[edgenum2]=Head2[u];
	Head2[u]=edgenum2;
}
void dfs1(int u,int ban){
	if (u==ban||connect[ban][u]) return;
	connect[ban][u]=true;
	for (int e=Head1[u];e;e=Next1[e]) dfs1(vet1[e],ban);
}
void dfs2(int u,int ban){
	if (u==ban||vis[u]) return;
	vis[u]=true;
	for (int e=Head2[u];e;e=Next2[e]) dfs2(vet2[e],ban);
}
void dfsbuild(int u){
	if (u==1||fa[u]) return;
	for (int i=2;i<=n;i++)
		if (i!=u&&!connect[i][u]) dfsbuild(i);
	for (int i=1;i<=n;i++) vis[i]=false;
	for (int i=2;i<=n;i++)
		if (i!=u&&!connect[i][u]) vis[fa[i]]=true;
	for (int i=1;i<=n;i++)
		if (i!=u&&!connect[i][u]&&!vis[i]){
			fa[u]=i;
			break;
		}
}
void dfstree(int u){
	sz[u]=1;
	for (int i=0;i<(int)vec[u].size();i++){
		dfstree(vec[u][i]);
		sz[u]+=sz[vec[u][i]];
	}
}
int dfsans(int u,int bel){
	if (flag[bel][u]) return sz[u];
	int res=0;
	for (int i=0;i<(int)vec[u].size();i++) res+=dfsans(vec[u][i],bel);
	return res;
}
int main(){
//	freopen("dominator.in","r",stdin);
//	freopen("dominator.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q); int u,v;
	for (int i=1;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		addedge1(u,v); addedge2(v,u);
	}
	for (int i=n;i<=m;i++){
		scanf("%d%d",&u,&v);
		addedge1(u,v); addedge2(v,u);
	}
	for (int i=1;i<=n;i++) dfs1(1,i);
	for (int i=2;i<=n;i++)
		if (!fa[i]) dfsbuild(i);
	for (int i=2;i<=n;i++) vec[fa[i]].push_back(i);
	dfstree(1);
	for (int i=1;i<=q;i++) scanf("%d%d",&s[i],&t[i]);
	for (int i=2;i<=n;i++){
		for (int j=1;j<=n;j++) vis[j]=false;
		dfs2(i,fa[i]);
		for (int j=1;j<=q;j++)
			if (connect[fa[i]][s[j]]&&vis[t[j]]) flag[j][i]=true;
	}
	for (int i=1;i<=q;i++) printf("%d\n",dfsans(1,i));
	return 0;
}
