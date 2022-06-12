#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int n,a[210000];
int lst; ll ans;
int main(){
    scanf("%d",&n); int lst=0;
    for (int i=0;i<=n-1;i++){
        scanf("%d",&a[i]);
        a[i]-=i; if (lst<a[i]){ puts("-1"); return 0;} lst=a[i];
        // cerr<<a[i]<<'#';
    }
    lst=INF;
    for (int i=n-1;i>=0;i--){
        if (a[i]==lst) continue;
        ans+=a[i]+i; lst=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}