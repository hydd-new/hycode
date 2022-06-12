#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,a[110000],mx,mn,tot;
bool work(){
    if (mn==mx){
        if (mn==n-1) return true;
        return mn<=(n>>1);
    }
    if (mn+1==mx){
        if (tot<=1) return false;
        return mn<=(tot>>1)+n-tot-1&&mn>=1+n-tot-1;
    }
    return false;
}
int main(){
    scanf("%d",&n);
    mn=INF; mx=-INF; tot=0;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mn=min(mn,a[i]); mx=max(mx,a[i]);
    }
    for (int i=1;i<=n;i++)
        if (a[i]==mx) tot++;
    if (work()) puts("Yes");
    else puts("No");
    return 0;
}