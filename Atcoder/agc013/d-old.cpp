#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
int n,m,dp[4100][4100][2];
int main(){
    scanf("%d%d",&n,&m);
    m--; n--;
    for (int i=0;i<=n;i++) dp[0][i][0]=1;
    for (int i=0;i<m;i++)
        for (int j=0;j<=n;j++){
            if (!j) dp[i][j][1]=(dp[i][j][1]+dp[i][j][0])%Mod,dp[i][j][0]=0;
            if (j>0){
                dp[i+1][j-1][0]=(dp[i+1][j-1][0]+dp[i][j][0])%Mod;
                dp[i+1][j-1][1]=(dp[i+1][j-1][1]+dp[i][j][1])%Mod;
            }
            dp[i+1][j][0]=(dp[i+1][j][0]+dp[i][j][0])%Mod;
            dp[i+1][j][1]=(dp[i+1][j][1]+dp[i][j][1])%Mod;
            
            dp[i+1][j][0]=(dp[i+1][j][0]+dp[i][j][0])%Mod;
            dp[i+1][j][1]=(dp[i+1][j][1]+dp[i][j][1])%Mod;
            if (j<n){
                dp[i+1][j+1][0]=(dp[i+1][j+1][0]+dp[i][j][0])%Mod;
                dp[i+1][j+1][1]=(dp[i+1][j+1][1]+dp[i][j][1])%Mod;
            }
        }
    int ans=0;
    for (int j=0;j<=n;j++){
        if (!j) dp[m][j][1]=(dp[m][j][1]+dp[m][j][0])%Mod,dp[m][j][0]=0;
        ans=(ans+dp[m][j][1])%Mod;
    }
    ans=(ans<<1)%Mod; ans=(ans<<1)%Mod;
    printf("%d\n",ans);
    return 0;
}
