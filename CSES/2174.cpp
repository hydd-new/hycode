//
// Created by hydd on 2022/6/12.
//
/*
 * 观察 1: max_digit(n)+1>=max_digit(n+1) (n>=0)
 *      推论: n-max_digit(n) 是不降的
 * 观察 2：答案是不降的，每次一定减去 max_digit(n)
 *      证明： 对 n 归纳
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
ll n,pw[20]; pii dp[10][20][10];
int max_digit(ll n){
    ll res=0;
    while (n) res=max(res,n%10),n/=10;
    return res;
}
pii calc(int d,int p,ll x){
    if (p==1){
        if (x>=d) return pii(10-d,2);
        else return pii(x-d+10,1);
    }
    ll pos=pw[p]-x;
    if (~dp[d][p][pos].first) return dp[d][p][pos];
    ll res=0;
    for (int i=9;i>=0;i--){
        pii tmp=calc(max(d,i),p-1,x%pw[p-1]);
        res+=tmp.second; x=tmp.first;
    }
    return (dp[d][p][pos]=pii(x+9*pw[p-1],res));
}
ll solve(ll n){
    if (n<=9) return 1;
//    if (n<=100) return solve(n-max_digit(n))+1;
    int p=0; while (pw[p+1]<n&&n%pw[p+1]>=pw[p+1]-9) p++;
    if (!p) return solve(n-max_digit(n))+1;
    ll x=n/pw[p]; pii tmp=calc(max_digit(x),p,n%pw[p]);
    return solve(tmp.first+(x-1)*pw[p])+tmp.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof(dp));
    pw[0]=1; for (int i=1;i<=18;i++) pw[i]=pw[i-1]*10;
    cin>>n;
    cout<<solve(n)<<'\n';
//    freopen("a.out","w",stdout);
//    for (n=1;n<=1000000;n++) cout<<solve(n)<<'\n';
    return 0;
}
