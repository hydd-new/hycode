#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
int n,m,dp[4100][4100];
int solve(int n,int m){
    memset(dp,0,sizeof(dp));
    for (int i=0;i<=n;i++) dp[0][i]=1;
    for (int i=0;i<m;i++)
        for (int j=0;j<=n;j++){
            if (j>0) dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%Mod;
            dp[i+1][j]=(dp[i+1][j]+dp[i][j])%Mod;
            dp[i+1][j]=(dp[i+1][j]+dp[i][j])%Mod;
            if (j<n) dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%Mod;
        }
    int res=0;
    for (int j=0;j<=n;j++) res=(res+dp[m][j])%Mod;
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
	/*if (n>=m){
		int ans=1;
		for (int i=1;i<=m+m;i++) ans=(ans<<1)%Mod;
		printf("%d\n",ans); return 0;
	}*/
	n--; m--;
    int ans=(solve(n,m)-solve(n-1,m)+Mod)%Mod;
    ans=(ans<<1)%Mod; ans=(ans<<1)%Mod;
    printf("%d\n",ans);
    return 0;
}
