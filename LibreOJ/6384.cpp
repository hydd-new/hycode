#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1ll<<60;
int n,k,now,x[11000];
ll s[11000],t[11000],dp[2][11000];
ll calc(int l,int r){
	if (l==n) return 0;
	ll res=((t[r]-t[l])-(s[r]-s[l])*l)*2;
	res+=((t[r-1]-t[l-1])-(s[r-1]-s[l-1])*r)*2;
	res+=((s[r]-s[l-1])-1ll*(r-l+1)*x[l-1])*(l-1);
	res+=(1ll*(r-l+1)*x[r+1]-(s[r]-s[l-1]))*(n-r);
    return res;
}
void solve(int l,int r,int x,int y){
	if (l>r) return;
	int mid=(l+r)>>1,m=x; ll tmp;
	for (int i=x;i<=y&&i<mid;i++){
		tmp=dp[now^1][i]+calc(i+1,mid-1);
		if (tmp<dp[now][mid]) dp[now][mid]=tmp,m=i;
	}
	solve(l,mid-1,x,m); solve(mid+1,r,m,y);
}
int main(){
	while (scanf("%d%d",&n,&k)==2){
		k++;
		for (int i=1;i<=n;i++){
			scanf("%d",&x[i]);
			s[i]=s[i-1]+x[i]; t[i]=t[i-1]+1ll*x[i]*i;
		}
		
		now=0; dp[now][0]=0;
		for (int i=1;i<=n+1;i++) dp[now][i]=INF;
		
		ll ans=INF;
		for (int t=1;t<=k;t++){
			now^=1;
			for (int i=0;i<=n+1;i++) dp[now][i]=INF;
			solve(0,n+1,0,n+1);
			ans=min(ans,dp[now][n+1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
