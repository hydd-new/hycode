#include<bits/stdc++.h>
using namespace std;
int T,n,m,col[11000],deg[11000]; bool flag[11000],tmp[11000],ans;
vector<int> vec[11000];
void topo_sort(){
	queue<int> que;
	for (int i=1;i<=n;i++)
		if (deg[i]<=1){
			deg[i]=1;
			que.push(i);
		}
	while (!que.empty()){
		int u=que.front(); que.pop();
		for (int v:vec[u])
			if (!flag[v]&&(--deg[v])<=1){
				flag[v]=true;
				que.push(v);
			}
	}
}
int v_tot,e_tot,x,y;
void dfs(int u){
	v_tot++;
	if (deg[u]==3)
		if (x) y=u;
		else x=u;
		
	for (int v:vec[u])
		if (!flag[v]){
			e_tot++;
			if (col[v]) ans&=(col[u]!=col[v]);
			else col[v]=3-col[u],dfs(v);
		}
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m); int u,v;
		for (int i=1;i<=n;i++){
			col[i]=0; deg[i]=0; flag[i]=false;
			vec[i].clear();
		}
		for (int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
			vec[v].push_back(u);
			deg[u]++; deg[v]++;
		}
		ans=true;
		topo_sort();
		for (int i=1;i<=n;i++)
			if (!flag[i]&&!col[i]){
				v_tot=0; e_tot=0;
				x=0; y=0; col[i]=1;
				dfs(i); e_tot>>=1;
				if (e_tot>=v_tot+2) ans=false;
				if (e_tot==v_tot+1){
					int cnt=0;
					for (int u:vec[x]) tmp[u]=true;
					for (int u:vec[y])
						if (tmp[u]) cnt++;
					for (int u:vec[x]) tmp[u]=false;
					if (cnt<2) ans=false;
				}
			}
		if (ans) puts("YES");
		else puts("NO");
	}
	return 0;
}