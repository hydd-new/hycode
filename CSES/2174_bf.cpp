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
ll n,pw[20]; map<int,int> mp;
int max_digit(ll n){
    ll res=0;
    while (n) res=max(res,n%10),n/=10;
    return res;
}
ll solve(ll n){
    if (mp.find(n)!=mp.end()) return mp[n];
    if (n<=9) return 1;
    return (mp[n]=solve(n-max_digit(n))+1);
}
int main(){
    freopen("a.ans","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    pw[0]=1; for (int i=1;i<=18;i++) pw[i]=pw[i-1]*10;
//    cin>>n;
    for (n=1;n<=1000000;n++) cout<<solve(n)<<'\n';
    return 0;
}
