#include<bits/stdc++.h>
using namespace std;
int n,m,f[190][190][190][17];
char s[190][190];
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for (int k=m;k>=1;k--)
        for (int i=1;i<=n;i++)
            f[i][i][k][0]=(s[i][k]==s[i][k+1]?f[i][i][k+1][0]:k);
    for (int k=1;k<=m;k++)
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                f[i][j][k][0]=(s[j][k]==s[j-1][k]?min(f[i][j-1][k][0],f[j][j][k][0]):0);
    for (int c=1;c<=16;c++)
        for (int k=1;k<=m;k++)
            for (int i=1;i<=n;i++){
                int x=i;
                for (int j=i;j<=n;j++){
                    while (x<j&&min(f[i][x][k][c-1],f[x+1][j][k][c-1])<=min(f[i][x+1][k][c-1],f[x+2][j][k][c-1])) x++;
                    f[i][j][k][c]=max(f[i][j][k][c-1],max(f[i][j][f[i][j][k][c-1]+1][c-1],min(f[i][x][k][c-1],f[x+1][j][k][c-1])));
                }
            }
    for (int c=0;c<=16;c++)
        if (f[1][n][1][c]==m){
            printf("%d\n",c);
            break;
        }
    return 0;
}
