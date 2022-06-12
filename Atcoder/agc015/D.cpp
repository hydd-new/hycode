#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
int main(){
    scanf("%lld%lld",&a,&b);
    if (a==b){ puts("1"); return 0;}
    ll x=1; while (x<=(a^b)) x<<=1;
    a&=(x-1); b&=(x-1); x>>=1;
    ll y=1; while (y<=(b^x)) y<<=1;
    // cerr<<x<<' '<<y<<endl;
    printf("%lld\n",x-a+(y+x-max(y,a)));
    return 0;
}
