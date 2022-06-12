#include<bits/stdc++.h>
using namespace std;
int n,m,x[110000],y[110000];
bool flag[410],vis[410],a[410][410];
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]);
    for (int i=1;i<=n;i++){
        flag[i]=true; vis[i]=true;
        for (int j=m;j>=1;j--){
            if (vis[x[j]]&&vis[y[j]]){ flag[i]=false; break;}
            if (!vis[x[j]]&&!vis[y[j]]) continue;
            vis[x[j]]=true; vis[y[j]]=true;
        }
        for (int j=1;j<=n;j++){
            a[i][j]=vis[j];
            vis[j]=false;
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (flag[i]&&flag[j]){
                ans++;
                for (int k=1;k<=n;k++)
                    if (a[i][k]&&a[j][k]){
                        ans--;
                        break;
                    }
            }
    printf("%d\n",ans);
    return 0;
}