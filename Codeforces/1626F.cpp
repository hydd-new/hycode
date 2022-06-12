#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,a[11000000],x,y,k,m;
int f[2][1100000],pw[1100000];
int gcd(int a,int b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n>>a[0]>>x>>y>>k>>m;
	for (int i=1;i<n;i++) a[i]=(1ll*a[i-1]*x+y)%m;
	
	int lcm=1,now=0; pw[0]=1;
	for (int i=1;i<k;i++) lcm=lcm/gcd(lcm,i)*i;
	for (int i=1;i<k;i++) pw[i]=1ll*pw[i-1]*n%Mod;
	int ans=0;
	for (int i=0;i<n;i++) ans=(ans+1ll*(a[i]/lcm)*lcm%Mod*k%Mod*pw[k-1])%Mod,a[i]%=lcm;
	for (int i=0;i<n;i++) f[now][a[i]]++;
	for (int j=1;j<=k;j++){
		now^=1; for (int i=0;i<lcm;i++) f[now][i]=0;
		for (int i=0;i<lcm;i++){
			f[now][i]=(f[now][i]+1ll*f[now^1][i]*(n-1))%Mod;
			f[now][i-i%j]=(f[now][i-i%j]+f[now^1][i])%Mod;
			ans=(ans+1ll*f[now^1][i]*i%Mod*pw[k-j])%Mod;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

