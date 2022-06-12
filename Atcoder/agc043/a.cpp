#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,dp[110][110]; char s[110][110];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for (int j=1;j<=m;j++){
			dp[i][j]=(i==1&&j==1?s[i][j]=='#':INF);
			if (i>1) dp[i][j]=min(dp[i][j],dp[i-1][j]+(s[i-1][j]!='#'&&s[i][j]=='#'));
			if (j>1) dp[i][j]=min(dp[i][j],dp[i][j-1]+(s[i][j-1]!='#'&&s[i][j]=='#'));
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}
