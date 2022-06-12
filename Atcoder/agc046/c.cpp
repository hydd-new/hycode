#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
char s[310]; int n,K,tot[310],dp[310][310][310];
int main(){
	scanf("%s",s); n=strlen(s);
	s[n++]='0';
	
	for (int i=n-1;i>=0;i--) tot[i]=(s[i]=='1'?tot[i+1]+1:0);
	scanf("%d",&K); dp[0][0][0]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<=i;j++)
			for (int k=0;k<=i&&k<=K;k++){
				int v=dp[i][j][k],pos=i-j;
				if (!v) continue;
				if (s[pos]=='0'){
					dp[i+1][j][k]=(dp[i+1][j][k]+v)%Mod;//野0
					dp[i+1][j+1][k+1]=(dp[i+1][j+1][k+1]+v)%Mod;//野1
				} else{
					if (tot[pos]<=j) dp[i+1][j-tot[pos]][k]=(dp[i+1][j-tot[pos]][k]+v)%Mod;//野0
					dp[i+1][j][k]=(dp[i+1][j][k]+v)%Mod;//野1
				}
			}
	int ans=0;
	for (int k=0;k<=n&&k<=K;k++) ans=(ans+dp[n][0][k])%Mod;
	printf("%d\n",ans);
	return 0;
}
