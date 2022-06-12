#include<bits/stdc++.h>
using namespace std;
int n,l,a[110000];
int main(){
    scanf("%d%d",&n,&l);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int pos=-1;
    for (int i=1;i<n;i++)
        if (a[i]+a[i+1]>=l) pos=i;
    if (pos==-1){ puts("Impossible"); return 0;}
    puts("Possible");
    for (int i=1;i<pos;i++) printf("%d\n",i);
    for (int i=n-1;i>pos;i--) printf("%d\n",i);
    printf("%d\n",pos);
    return 0;
}
