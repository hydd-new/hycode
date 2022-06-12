#include<bits/stdc++.h>
using namespace std;
int n,mx[210000],ans[210000];
vector<int> vec[210000];
map<int,int> tot[210000];
void dfs(int u,int f){
	for (int v:vec[u]){
		if (v==f) continue;
		mx[v]=max(mx[u],u); dfs(v,u);
	}
}
int query(int u,int f,int x){
	if (tot[u].find(x)!=tot[u].end()) return tot[u][x];
	int res=1;
	for (int v:vec[u]){
		if (v==f||v>x) continue;
		res+=query(v,u,x);
	}
	tot[u][x]=res;
	return res;
}
void solve(int u,int f){
	if (u==1) ans[u]=0;
	else{
		ans[u]=ans[f]+query(u,f,mx[u]);
		if (u<mx[f]) ans[u]-=query(u,f,mx[f]);
	}
	for (int v:vec[u]){
		if (v==f) continue;
		solve(v,u);
	}
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1,0); solve(1,0);
	for (int i=2;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
