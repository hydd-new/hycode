#include<bits/stdc++.h>
using namespace std;
int T,n,m,fa[11000];
int findset(int u){
	if (u!=fa[u]) fa[u]=findset(fa[u]);
	return fa[u];
}

void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dfs(int u){
	if (vis[u]) return;
	vis[u]=true; a[++tot]=u; cnt+=deg[u];
	if (deg[u]==3){
		if (x==-1) x=u;
		else if (y==-1) y=u;
		else flag=true;
	} else if (deg[u]>3) flag=
	for (int e=Head[u];e;e=Next[e]) dfs(vet[e]);
}
void work(){
	for (int i=1;i<=n;i++)
		if (!vis[i]){
			tot=0; cnt=0;
			dfs(i); cnt>>=1;
			if (cnt>=tot+2){
				puts("NO");
				return;
			}
			for (int j=1;j<=tot;j++)
				if (deg[a[j]]==1) que.push(a[j]);
			while (!que.empty()){
				int u=que.front(); que.pop();
				flag[u]=true;
				for (int v:vec[u]){
					deg[v]--;
					if (deg[v]==1) que.push(v);
				}
			}
		}
}*/
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m); edgenum=0;
		for (int i=1;i<=n;i++) Head[i]=0,deg[i]++,vis[i]=false;
		for (int i=1;i<=n+n;i++) fa[i]=i;
		int u,v;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			deg[u]++; deg[v]++;
			fa[findset(u)]=findset(v+n);
			fa[findset(v)]=findset(u+n);
			addedge(u,v); addedge(v,u);
		}
		flag=false;
		for (int i=1;i<=n;i++) flag|=(findset(i)==findset(i+n));
		if (flag){
			puts("NO");
			continue;
		}
		work();
		for (int i=1;i<=n;i++){
			
		}
	}
	return 0;
}
