#include<bits/stdc++.h>
#definelllong long
#define x first
#define y second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
const int N=2e5+100;
constllinf=1LL<<60;
ll a[N],f[N],g[N];
pll b[N],q[N];
void solve(){
 int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;++i)cin>>a[i];
	for (int i=1;i<=m;++i)cin>>b[i].x>>b[i].y;
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	a[++n]=inf;
	for (int i=1,j=1;i<=n;++i){
		int s=0;
		while (j<=m&&b[j].x<=a[i]){
			if (b[j].y<a[i])q[++s]=b[j];
			++j;
		}
		q[++s].x=a[i-1];
		sort(q+1,q+1+s);
		f[i]=g[i]=inf;
		ll mn=a[i];
		for (int k=s;k>=1;--k){
			ll u=q[k].x-a[i-1],v=a[i]-mn;
			ll t=min(f[i-1]+u*2,g[i-1]+u);
			f[i]=min(f[i],t+v);
			g[i]=min(g[i],t+v*2);
			mn=min(mn,q[k].y);
		}
	}
	cout<<f[n]<<endl;
}
int main(){
	a[0]=-inf;
	int t;
	cin>>t;
	while (t--)solve();
}
