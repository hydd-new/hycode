#include<bits/stdc++.h>
using namespace std;
int n,a[210000];
int cnt,b[210000];
bool vis[210000];
int main(){
    scanf("%d",&n); int cnt=0;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if (a[i]!=b[cnt]) b[++cnt]=a[i];
    }
    int x=b[cnt];
    for (int i=1;i<cnt;i++)
        if (b[i]>b[i+1]&&!vis[b[i]]){
            x=b[i];
            break;
        } else
			if (vis[b[i]]) x=b[i];
			else vis[b[i]]=true;
    for (int i=1;i<=n;i++)
        if (a[i]!=x) printf("%d ",a[i]);
    return 0;
}
