#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1ll<<60;
int n,a[11000],d[11000]; ll dp[510000];
ll sqr(ll x){ return x*x;}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) d[i]=a[i+1]-a[i];
	sort(d+1,d+n);
	
	for (int i=0;i<=500000;i++) dp[i]=INF;
	dp[0]=0; int lim=0,sum=0;
	for (int i=1;i<n;i++){
		if (!d[i]) continue;
		for (int s=lim;s>=0;s--){
			if (dp[s]==INF) continue;
			dp[s+sum+d[i]]=min(dp[s+sum+d[i]],dp[s]+sqr(sum+d[i]));
			dp[s+i*d[i]]=min(dp[s+i*d[i]],dp[s]+2*s*d[i]+i*sqr(d[i]));
			dp[s]=INF;
		}
		lim+=i*d[i]; sum+=d[i];
	}
	ll ans=INF;
	for (int i=0;i<=lim;i++)
		if (dp[i]!=INF) ans=min(ans,n*dp[i]-1ll*i*i);
	printf("%lld\n",ans);
	return 0;
}
