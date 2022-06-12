#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int inv2=(Mod+1)>>1;
typedef long long ll;
int n;
ll mu[1100000],inv[1100000];
ll a[1100000],b[1100000];
int main(){
	inv[1]=1;
	for (int i=2;i<=1000000;i++) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	mu[1]=1;
	for (int i=1;i<=1000000;i++)
		for (int j=i+i;j<=1000000;j+=i)
			mu[j]-=mu[i];
	scanf("%d",&n); int x;
	ll ans=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]++; ans-=x;
	}
	for (int i=1;i<=1000000;i++) a[i]=a[i]*i%Mod;
	for (int i=1;i<=1000000;i++)
		for (int j=i;j<=1000000;j+=i)
			b[i]=(b[i]+a[j])%Mod;
	for (int i=1;i<=1000000;i++){
		ll res=0;
		for (int j=i,t=1;j<=1000000;j+=i,t++) res=(res+b[j]*b[j]%Mod*inv[t])%Mod;
		ans=(ans+res*mu[i])%Mod;
	}
	printf("%lld\n",(ans+Mod)*inv2%Mod);
	return 0;
}