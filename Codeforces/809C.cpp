#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
typedef long long ll;
typedef pair<ll,ll> pii;
int q,a[32],b[32],c[32];
pii dp[32][2][2][2];
pii solve(int d,bool lx,bool ly,bool lk){
	if (d==-1) return pii(1,1);
	if (~dp[d][lx][ly][lk].first) return dp[d][lx][ly][lk];
	int limx=(lx?a[d]:1),limy=(ly?b[d]:1),limk=(lk?c[d]:1);
	int res=0,sum=0; pii tmp;
	for (int i=0;i<=limx;i++)
		for (int j=0;j<=limy;j++)
			if ((i^j)<=limk){
				tmp=solve(d-1,lx&&(i==limx),ly&&(j==limy),lk&&((i^j)==limk));
				res=(res+tmp.first)%Mod; sum=(sum+tmp.second+tmp.first*((i^j)<<d))%Mod;
			}
	return (dp[d][lx][ly][lk]=pii(res,sum));
}
ll calc(int x,int y,int k){
	if (x<0||y<0) return 0;
	memset(dp,-1,sizeof(dp));
	for (int i=0;i<=30;i++) a[i]=(x&1),x>>=1;
	for (int i=0;i<=30;i++) b[i]=(y&1),y>>=1;
	for (int i=0;i<=30;i++) c[i]=(k&1),k>>=1;
	return solve(30,1,1,1).second;
}
int main(){
	scanf("%d",&q); int x1,y1,x2,y2,k;
	while (q--){
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&k); x1--; y1--; x2--; y2--; k--;
		printf("%lld\n",((calc(x2,y2,k)-calc(x2,y1-1,k)-calc(x1-1,y2,k)+calc(x1-1,y1-1,k))%Mod+Mod)%Mod);
	}
	return 0;
}
