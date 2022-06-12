#include<bits/stdc++.h>
using namespace std;
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	s[++top]=u; 
	for (int v:vec[u]){
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if (low[v]>=dfn[u]){
				tot++; int w;
				do{
					w=s[top--];
					vcc[w]=tot;
					vc2[w].push_back(tot);
					vc2[tot].push_back(w);
				} while (w!=v);
				vc2[u].push_back(tot);
				vc2[tot].push_back(u);
			}
		} else low[u]=min(low[u],dfn[v]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++) cin>>w[i];
	for (int i=1;i<=m;i++){
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	tarjan(1,0);
	return 0;
}

