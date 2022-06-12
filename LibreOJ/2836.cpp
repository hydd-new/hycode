#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q; ll f[510000];
vector<int> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>q; f[0]=1; int x;
	for (int i=1;i<=n;i++){
		cin>>x;
		f[i]=((x+f[i-1]-1)/f[i-1])*f[i-1];
		if (i==1||f[i]!=f[i-1]) v.push_back(i);
	}
	v.push_back(n+1);
	
	ll l,r,t;
	while (q--){
		cin>>t>>l>>r; ll ans=(l<=t&&t<=r);
		for (int i=0;i+1<v.size();i++){
			ll x=v[i],y=v[i+1]-1;
			ll d=t/f[x]*f[x];
			ans+=max(min(-x+d,r)-max(-y+d,l)+1,0ll);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

