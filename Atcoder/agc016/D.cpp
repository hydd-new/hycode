#include<bits/stdc++.h>
using namespace std;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    for (int i=1;i<=n;i++)
        if (a[i]!=b[i]||i==n){
            num[++cnt]=a[i]; num[++cnt]=b[i];

        }
    return 0;
}
