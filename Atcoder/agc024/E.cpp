#include<bits/stdc++.h>
using namespace std;
int n,K,m,f[310][310],C[310][310];
int main(){
    scanf("%d%d%d",&n,&K,&m);
    for (int i=0;i<=n;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%m;
    }
    for (int j=0;j<=K;j++) f[0][j]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=K;j++){
            f[i][j]=f[i][j-1];
            for (int k=1;k<=i;k++)
                f[i][j]=(f[i][j]+1ll*f[k-1][j-1]*f[i-k][j]%m*C[i][i-k+1])%m;
        }
    printf("%d\n",f[n][K]);
    return 0;
}