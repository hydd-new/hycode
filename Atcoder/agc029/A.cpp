#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[210000]; int n;
int main(){
    scanf("%s",s+1); n=strlen(s+1);
    ll ans=0; int tot=0;
    for (int i=1;i<=n;i++)
        if (s[i]=='W') ans+=tot;
        else tot++;
    printf("%lld\n",ans);
    return 0;
}