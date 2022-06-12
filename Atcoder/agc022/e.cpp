#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
//-, 0,1,00,01,11,001,011,0011;
const int trans[2][9]={{1,3,4,1,6,7,4,8,7},{2,0,5,1,2,5,4,5,7}};
int n,dp[310000][10];
char s[310000];
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=8;j++){
			if (s[i]!='1') dp[i][trans[0][j]]=(dp[i][trans[0][j]]+dp[i-1][j])%Mod;
			if (s[i]!='0') dp[i][trans[1][j]]=(dp[i][trans[1][j]]+dp[i-1][j])%Mod;
		}
	printf("%lld\n",((long long)dp[n][2]+dp[n][5]+dp[n][7]+dp[n][8])%Mod);
	return 0;
} 

