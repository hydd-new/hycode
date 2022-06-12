#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y;
char s[210000],t[210000];
bool solve1(){
    int l=1,r=n;
    for (int i=k;i>=1;i--){
        if (t[i]=='D') l--;
        if (t[i]=='U') r++;
        l=max(1,l); r=min(n,r);
        if (s[i]=='D') r--;
        if (s[i]=='U') l++;
        if (l>r) return false;
    }
    return l<=x&&x<=r;
}
bool solve2(){
    int l=1,r=m;
    for (int i=k;i>=1;i--){
        if (t[i]=='R') l--;
        if (t[i]=='L') r++;
        l=max(1,l); r=min(m,r);
        if (s[i]=='R') r--;
        if (s[i]=='L') l++;
        if (l>r) return false;
    }
    return l<=y&&y<=r;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&x,&y);
    scanf("%s%s",s+1,t+1);
    if (solve1()&&solve2()) puts("YES");
    else puts("NO");
    return 0;
}