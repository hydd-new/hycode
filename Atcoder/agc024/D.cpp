#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d,rt; ll ans;
int dep[110],fa[110],mx[110];
vector<int> vec[110];
void getrt(int u,int f){
	dep[u]=dep[f]+1; fa[u]=f;
	if (dep[u]>dep[rt]) rt=u;
	for (int v:vec[u]){
		if (v==f) continue;
		getrt(v,u);
	}
}
void dfs(int u,int f){
	dep[u]=dep[f]+1; int tot=0;
	for (int v:vec[u]){
		if (v==f) continue;
		tot++; dfs(v,u);
	}
	mx[dep[u]]=max(mx[dep[u]],tot);
}
void solve(int u){
	for (int i=1;i<d;i++) mx[i]=0;
	dep[0]=0; dfs(u,0);
	ll tmp=1; for (int i=1;i<d;i++) tmp*=mx[i];
	ans=min(ans,tmp);
}
void solve(int u,int v){
	for (int i=1;i<=d;i++) mx[i]=0;
	mx[1]=2;
	dep[v]=1; dfs(u,v);
	dep[u]=1; dfs(v,u);
	ll tmp=1; for (int i=1;i<=d;i++) tmp*=mx[i];
	ans=min(ans,tmp);
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	int x,y;
	getrt(1,0); x=rt;
	getrt(x,0); y=rt;
	d=(dep[y]+1)>>1; ans=1ll<<60;
	printf("%d ",d);
	if (dep[y]&1){
		int u=y;
		for (int i=1;i<d;i++) u=fa[u];
		solve(u);
		for (int v:vec[u]) solve(u,v);
	} else{
		int u=y;
		for (int i=1;i<d;i++) u=fa[u];
		solve(u,fa[u]);
	}
	printf("%lld\n",ans);
	return 0;
}
