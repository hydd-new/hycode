#include<bits/stdc++.h>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
typedef pair<int,int> pii;
int n,m,d[1100][1100]; char s[1100];
int head,tail; pii que[1100000];
int main(){
    scanf("%d%d",&n,&m);
    head=1; tail=0;
    for (int i=1;i<=n;i++){
        scanf("%s",s+1);
        for (int j=1;j<=m;j++){
            d[i][j]=-1;
            if (s[j]=='#') que[++tail]=pii(i,j),d[i][j]=0;
        }
    }
    int ans=0;
    while (head<=tail){
        int x=que[head].first,y=que[head].second; head++;
        ans=d[x][y];// cerr<<x<<' '<<y<<endl;
        for (int k=0;k<4;k++){
            int nx=x+dx[k],ny=y+dy[k];
            if (d[nx][ny]==-1){
                d[nx][ny]=d[x][y]+1;
                que[++tail]=pii(nx,ny);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}