#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,p[110000]; bool vis[110000];
vector<int> vec[110000];
void dfs(int u){
	vis[u]=true; p[++cnt]=u;
	for (int v:vec[u])
		if (!vis[v]){ dfs(v); break;}
}
int main(){
	scanf("%d%d",&n,&m); int u,v;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	cnt=0; dfs(1);
	reverse(p+1,p+cnt+1);
	cnt--; dfs(1);
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++) printf("%d ",p[i]);
	return 0;
}
