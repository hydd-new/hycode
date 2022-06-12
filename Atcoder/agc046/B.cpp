#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
typedef long long ll;
int a,b,c,d; ll f[3100][3100];
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	f[a][b]=1;
	for (int i=a;i<=c;i++)
		for (int j=b;j<=d;j++){
			if (i==a&&j==b) continue;
			f[i][j]=(f[i-1][j]*j+f[i][j-1]*i-f[i-1][j-1]*(i-1)*(j-1))%Mod;
		}
	printf("%lld\n",(f[c][d]+Mod)%Mod);
	return 0;
}
