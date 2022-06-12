#include<bis/stdc++.h>
using namespace std;
void dfs(int u){
	dfs(ls[u]);
	dfs(rs[u]);
	
	int x=--s[ls[u]].lower_bound(pii(a[u]+1,0))->second;
	int y=--s[rs[u]].lower_bound(pii(a[u]+1,0))->second;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	cin>>m; int x,y,c;
	for (int i=1;i<=m;i++){
		cin>>x>>y>>c;
		vec[x].push_back(pii(y,c));
	}
	for (int i=1;i<=n;i++){
		int t=top;
		while (t&&a[i]>a[s[t]]) t--;
		
		if (t) rs[s[t]]=i;
		if (t<top) ls[i]=s[t+1];
		s[++t]=i; top=t;
	}
	
	dfs(s[1]); 
	
	return 0;
}

