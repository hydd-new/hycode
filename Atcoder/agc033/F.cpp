#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int n,k,f[2100][2100];
ll fac[4100000],inv[4100000];
ll C(int n,int m){
	if (n<0||n<m) return 0;
	return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main(){
	scanf("%d%d",&n,&k);
	if (k==1) return puts("1"),0;
	fac[0]=1; for (int i=1;i<=4000000;i++) fac[i]=fac[i-1]*i%Mod;
	inv[1]=1; for (int i=2;i<=4000000;i++) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	inv[0]=1; for (int i=1;i<=4000000;i++) inv[i]=inv[i-1]*inv[i]%Mod;
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=i;j>=1;j--)
			f[i][j]=(f[i][j+1]+C(i*k-j-1,k-2)*f[i-1][j-1]%Mod)%Mod;
		f[i][0]=f[i][1];
	}
	printf("%lld\n",fac[n]*f[n][0]%Mod);
	return 0;
}
