#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
typedef long long ll;
int n,m,s,t,dp[110000];
vector<int> vec[110000];
ll qpow(ll x,int a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
int dfs(int u){
	if (dp[u]!=-1) return dp[u];
	ll res=0;
	for (int v:vec[u]) res+=dfs(v);
	dp[u]=res%Mod*qpow(vec[u].size(),Mod-2)%Mod;
	return dp[u];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	
	int u,v;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		vec[v].push_back(u);
	}
	
	ll res=1,tmp=1;
	for (int i=2;i<=n;i++){
		res=res*(vec[i].size()+(i==t))%Mod;
		tmp=tmp*vec[i].size()%Mod;
	}
	
	memset(dp,-1,sizeof(dp));
	dp[t]=tmp;
	for (int i=1;i<=n;i++) dfs(i);
	printf("%lld\n",(res-dp[s]*qpow(vec[t].size(),Mod-2)%Mod+Mod)%Mod);
	return 0;
}
