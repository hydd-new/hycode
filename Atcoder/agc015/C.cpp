#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[2100][2100],s[2100][2100],t[2100][2100];
char tmp[2100];
int calc0(int x1,int y1,int x2,int y2){
    return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
}
int calc1(int x1,int y1,int x2,int y2){
    return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}
int calc2(int x1,int y1,int x2,int y2){
    return t[x2][y2]-t[x1-1][y2]-t[x2][y1-1]+t[x1-1][y1-1];
}
int calc(int x1,int y1,int x2,int y2){
    return calc0(x1,y1,x2,y2)-calc1(x1+1,y1,x2,y2)-calc2(x1,y1+1,x2,y2);
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=n;i++){
        scanf("%s",tmp+1);
        for (int j=1;j<=m;j++) a[i][j]=tmp[j]-'0';
    }
    for (int i=2;i<=n;i++)
        for (int j=1;j<=m;j++)
            s[i][j]=(a[i-1][j]&&a[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=2;j<=m;j++)
            t[i][j]=(a[i][j-1]&&a[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            t[i][j]+=t[i-1][j]+t[i][j-1]-t[i-1][j-1];
        }
    int x1,y1,x2,y2;
    while (q--){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",calc(x1,y1,x2,y2));
    }
    return 0;
}