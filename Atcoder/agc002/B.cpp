#include<bits/stdc++.h>
using namespace std;
int n,m,a[110000]; bool b[110000];
int main(){
    scanf("%d%d",&n,&m); b[1]=true;
    for (int i=1;i<=n;i++) a[i]=1;
    int x,y;
    for (int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        a[x]--; a[y]++;
        if (b[x]) b[y]=true,b[x]=(a[x]!=0);
    }
    int ans=0;
    for (int i=1;i<=n;i++) ans+=b[i];
    printf("%d\n",ans);
    return 0;
}