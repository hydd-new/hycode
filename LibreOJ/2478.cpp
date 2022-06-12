#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> node;
typedef pair<int,int> pii;
const ll INF=1ll<<60;
int n,k; node dp[310000][4],tmp[4];
vector<pii> vec[310000];
node operator+(const node &a,const node &b){ return node(a.first+b.first,a.second+b.second);}
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
void dfs(int u,int f,ll m){
	dp[u][0]=node(0,0);
	dp[u][1]=node(m,1);
	dp[u][2]=node(-INF,0);
	int v,c;
	for (pii t:vec[u]){
		v=t.first; c=t.second;
		if (v==f) continue;
		dfs(v,u,m);
		tmp[0]=dp[u][0]; tmp[1]=dp[u][1]; tmp[2]=dp[u][2];
		dp[u][0]=tmp[0]+dp[v][2]; dp[u][1]=tmp[1]+dp[v][2]; dp[u][2]=tmp[2]+dp[v][2];
		dp[u][1]=max(dp[u][1],tmp[0]+dp[v][1]+node(c,0));
		dp[u][2]=max(dp[u][2],tmp[1]+dp[v][1]+node(c-m,-1));
	}
	dp[u][2]=max(dp[u][2],max(dp[u][0],dp[u][1]));
}
bool check(ll m){
	dfs(1,0,m);
	return dp[1][2].second>=k+1;
}
int main(){
	n=read(); k=read(); int u,v,c;
	for (int i=1;i<n;i++){
		u=read(); v=read(); c=read();
		vec[u].push_back(pii(v,c));
		vec[v].push_back(pii(u,c));
	}
	ll l=-3e11,r=3e11,mid;
	while (l<r){
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	check(l);
	printf("%lld\n",dp[1][2].first-l*(k+1));
	return 0;
}
