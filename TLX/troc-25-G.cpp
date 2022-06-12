//
// Created by hydd on 2022/6/12.
//
/* 关键点：考虑哪些最终状态是可达的。
 * 观察 1： 所有相同数字一定在一个连续的区间，且覆盖过程中不会发生相对顺序改变。
 * 观察 2: 假设你知道了最终序列 b，对于原先的 a_i 覆盖了 b 中的区间 [l,r]，那么 a 中 min(i,l) 和 max(i,r) 之间的数必须 <= a_i
 * 这是充要条件，按照 a_i 从小到大进行覆盖，只要相对顺序不变一定可以完成。
 * 设 dp[i][j][k][0/1] 表示 a_{1..i}, b_{1..j}，使用了 k 次操作（b 不完全在原位的有 k 种数），a_i 是否使用（0/1），结果的方案数。
 */
#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,K,a[310],top,s[310];
int L[310],R[310];
int dp[310][310][310][2];

inline bool check(int i,int j){
    return j>L[i]&&j<R[i];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>K;
    for (int i=1;i<=n;i++) cin>>a[i];

    top=0; s[0]=0;
    for (int i=1;i<=n;i++){
        while (top&&a[s[top]]<a[i]) top--;
        L[i]=s[top]; s[++top]=i;
    }

    top=0; s[0]=n+1;
    for (int i=n;i>=1;i--){
        while (top&&a[s[top]]<a[i]) top--;
        R[i]=s[top]; s[++top]=i;
    }

    dp[1][0][0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=n;j++)
            for (int k=0;k<=K;k++){
                if (i<n) dp[i+1][j][k][0]=(dp[i+1][j][k][0]+(dp[i][j][k][0]+dp[i][j][k][1])%Mod)%Mod;
                if (j<n&&check(i,j+1)){
                    int op=(i!=j+1);
                    dp[i][j+1][k+op][op]=(dp[i][j+1][k+op][op]+dp[i][j][k][0])%Mod;
                    dp[i][j+1][k][1]=(dp[i][j+1][k][1]+dp[i][j][k][1])%Mod;
                }
            }
    
    int ans=0;
    for (int k=0;k<=K;k++) ans=(ans+(dp[n][n][k][0]+dp[n][n][k][1])%Mod)%Mod;
    cout<<ans<<'\n';
    return 0;
}
