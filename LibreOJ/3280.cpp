#include<bits/stdc++.h>
using namespace std;
const int N=210000;
const int INF=0x3f3f3f3f;
int n,m,fa[N],bel[N],sz[N];
int vis[N],used[N],col[N];
int all,rt,mn,ans,now;
vector<int> vec[N],c[N];
queue<int> que;
void getrt(int u,int f){
	int res=0;
	sz[u]=1;
	for (int v:vec[u]){
		if (vis[v]||v==f) continue;
		getrt(v,u); sz[u]+=sz[v];
		res=max(res,sz[v]);
	}
    res=max(res,all-sz[u]);
	if (res<mn) mn=res,rt=u;
}
void dfs(int u,int f){
	fa[u]=f; bel[u]=now;
	for (int v:vec[u]){
		if (vis[v]||v==f) continue;
		dfs(v,u);
	}
}
void solve(int u){
	used[col[u]]=++now; dfs(u,0);
	int cnt=0;
	while (!que.empty()) que.pop();
	que.push(col[u]); bool flag=true;
	while (!que.empty()){
		int v=que.front(); que.pop(); cnt++;
		for (int w:c[v]){
			if (bel[w]!=now){
				flag=false;
				break;
			}
			for (int x=fa[w];x;x=fa[x])
				if (used[col[x]]!=now){
					que.push(col[x]);
					used[col[x]]=now;
				} else break;
		}
		if (!flag) break;
	}
	if (flag) ans=min(ans,cnt);	
	vis[u]=true; int tmp=all;
	for (int v:vec[u]){
		if (vis[v]) continue;
		all=sz[v]<sz[u]?sz[v]:tmp-sz[u]; mn=INF; getrt(v,u);
		solve(rt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m; int u,v;
	for (int i=1;i<n;i++){
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for (int i=1;i<=n;i++){
		cin>>col[i];
		c[col[i]].push_back(i);
	}
	ans=m;
    all=n; mn=INF; getrt(1,0);
    solve(rt);
	cout<<ans-1<<endl;
	return 0;
}

