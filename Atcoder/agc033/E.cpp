#include<bits/stdc++.h>
using namespace std;
int n,a[110000];
int solve(int x,int y){
    if (a[x+1]<=y&&((a[x]-y)&1)) return 1;
    if (a[x+1]<=y){
        if (a[x+1]<y) return 0;
        else return solve(x+1,y)^1;
    }
    return solve(x+1,y+1);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    if (solve(1,1)) puts("First");
    else puts("Second");
    return 0;
}