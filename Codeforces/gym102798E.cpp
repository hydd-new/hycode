#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int n,m,a[16]; ll f[1<<15][210],g[1<<15],A[1<<8][210],B[1<<8][210],inv[16];
int tot[1<<15],sum[1<<15],C[210][210];
int main(){
	freopen("nnntxdy.in","r",stdin);
	freopen("nnntxdy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	
	inv[1]=1; for (int i=2;i<=n;i++) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	for (int i=0;i<=m;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
	
	int upperlim=(1<<n)-1;
	for (int s=1;s<=upperlim;s++)
		for (int i=0;i<n;i++)
			if (s&(1<<i)){
				tot[s]++;
				sum[s]+=a[i];
			}
	
	int mid=n>>1;
	A[0][0]=1;
	for (int s=1;s<(1<<mid);s++){
		int x;
		for (int i=0;i<n;i++)
			if (s&(1<<i)) x=i;
		int y=1<<x;
		for (int i=0;i<=m;i++)
			for (int j=0;j<=min(a[x]-1,m-i);j++)
				A[s][i+j]=(A[s][i+j]+C[i+j][i]*A[s^y][i])%Mod;
	}
	B[0][0]=1;
	for (int s=1;s<(1<<(n-mid));s++){
		int x;
		for (int i=0;i<n;i++)
			if (s&(1<<i)) x=i;
		int y=1<<x;
		for (int i=0;i<=m;i++)
			for (int j=0;j<=min(a[x+mid]-1,m-i);j++)
				B[s][i+j]=(B[s][i+j]+C[i+j][i]*B[s^y][i])%Mod;
	}
	for (int s=0;s<(1<<mid);s++)
		for (int t=0;t<(1<<(n-mid));t++){
			int sta=(s|(t<<mid))^upperlim;
			int lim=m-sum[sta];
			for (int i=0;i<=lim;i++)
				g[sta]=(g[sta]+A[s][i]*B[t][lim-i]%Mod*C[lim][i])%Mod;
		}
	
	f[0][0]=1;
	for (int s=0;s<=upperlim;s++){
		for (int i=0;i<m-sum[s];i++) f[s][i+1]=(f[s][i+1]+f[s][i]*inv[n-tot[s]])%Mod;
		for (int i=0;i<=m-sum[s];i++)
			for (int j=0;j<n;j++)
				if (!(s&(1<<j))&&i+1>=a[j])
					f[s|(1<<j)][i+1-a[j]]=(f[s|(1<<j)][i+1-a[j]]+C[i][a[j]-1]*f[s][i]%Mod*inv[n-tot[s]])%Mod;
	}
	
	int ans=0;
	for (int s=0;s<=upperlim;s++)
		if (sum[s]<=m) ans=(ans+f[s][m-sum[s]]*g[s]%Mod*tot[s])%Mod;
	printf("%d\n",ans);
	return 0;
}
