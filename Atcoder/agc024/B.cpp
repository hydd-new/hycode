#include<bits/stdc++.h>
using namespace std;
int n,a[210000];
int main(){
    scanf("%d",&n); int x;
    for (int i=1;i<=n;i++){
        scanf("%d",&x);
        a[x]=i;
    }
    int ans=n+1;
    for (int i=1,j=1;i<=n;i++){
        if (j<i) j=i;
        while (j<n&&a[j]<a[j+1]) j++;
        ans=min(ans,n-(j-i+1));
    }
    printf("%d\n",ans);
    return 0;
}