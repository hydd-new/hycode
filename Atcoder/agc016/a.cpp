#include<bits/stdc++.h>
using namespace std;
int n,Ans[110],lst[110];
char s[110];
int main(){
    scanf("%s",s+1); n=strlen(s+1);
    for (int i=1;i<=n;i++){
        int u=s[i]-'a';
        Ans[u]=max(Ans[u],i-lst[u]-1); lst[u]=i;
    }
    int ans=n;
    for (int u=0;u<26;u++){
        Ans[u]=max(Ans[u],(n+1)-lst[u]-1);
        ans=min(ans,Ans[u]);
    }
    printf("%d\n",ans);
    return 0;
}