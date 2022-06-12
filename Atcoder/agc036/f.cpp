#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[510],b[510];
ll f[510][510];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<2*n;i++){
		a[i]=-1; b[i]=-1;
		for (int j=0;j<2*n;j++){
			if (j*j+i*i<n*n) a[i]=j;
			if (j*j+i*i<=4*n*n) b[i]=j;
		}
	}
	ll ans=0;
	for (int k=0;k<=(n<<1);k++){
		memset(f,0,sizeof(f));
		f[0][0]=1;
		int tot1=0,tot2=0,pos1=n-1,pos2=(n<<1)-1;
		for (int i=0;i<(n<<1);i++){
			int now;
			if (pos2<n||pos1>=0&&a[pos1]<b[pos2]) now=pos1--,tot1++;
			else now=pos2--,tot2++;
			for (int j=0;j<=k&&j<=i;j++){
				if (now<n){
					f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*(a[now]+1-j-tot2))%m;//违反下界
					f[i+1][j]=(f[i+1][j]+f[i][j]*(b[now]+1-k-n-(tot1-1)+j))%m;//不违反下界
				}
				else f[i+1][j]=(f[i+1][j]+f[i][j]*(b[now]+1-j-(tot2-1)))%m;
			}
		}
		ans=(ans+(k&1?m-1:1)*f[n<<1][k])%m;
	}
	printf("%lld\n",ans);
	return 0;
}
