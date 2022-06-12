#include<bits/stdc++.h>
using namespace std;
int n,m,f[6100][12100];
int main(){
	scanf("%d%d",&n,&m); n=3*n;
	f[0][0+n]=1;
	for (int i=0;i<n;i++)
		for (int j=-i;j<=i;j++){
			f[i+1][j+1+n]=(f[i+1][j+1+n]+f[i][j+n])%m;
			f[i+2][j-1+n]=(f[i+2][j-1+n]+1ll*f[i][j+n]*(i+1))%m;
			f[i+3][j+n]=(f[i+3][j+n]+1ll*f[i][j+n]*(i+1)%m*(i+2))%m;
		}
	int ans=0;
	for (int i=0;i<=n;i++) ans=(ans+f[n][i+n])%m;
	printf("%d\n",ans);
	return 0;
}
