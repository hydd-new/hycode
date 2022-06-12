#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=998244353;
const ll inv2=(Mod+1)/2;
ll l,r,v;
ll calc(ll x){ x%=Mod; return (x*(x-1)/2)%Mod;}
ll solve(ll d,ll a,ll b,ll v,bool x,bool y){
	if (d==-1) return 1;
	if (!x&&!y) return (1ll<<(d+1));
	int res=0;
	for (int i=0;i<=1;i++)
		for (int j=0;j<=1;j++)
			if ((!x||i<=((a>>d)&1))&&(!y||j<=((b>>d)&1))&&(i^j)==((v>>d)&1)) res=(res+solve(d-1,a,b,v,x&&(i==((a>>d)&1)),y&&(j==((b>>d)&1))))%Mod;
	return res;
}
ll calc(ll a,ll b,ll v){//0..a ^ 0..b = v
	if (a<0||b<0) return 0;
	return solve(60,a,b,v,true,true);
}
ll calcc(ll l1,ll r1,ll l2,ll r2,ll v){
	if (l1<=r1&&l2<=r2) return (calc(r1,r2,v)+Mod-calc(r1,l2-1,v)+Mod-calc(l1-1,r2,v)+calc(l1-1,l2-1,v))%Mod;
	return 0;
}
bool check(ll v,ll l,ll r){ return l<=v&&v<=r;}
int main(){
	cin>>l>>r>>v;
	if (r-l<=10){
		ll ans=0;
		for (ll i=l;i<=r;i++){
			ll sum=0;
			for (ll j=i;j<=r;j++){
				sum^=j;
				if (sum==v) ans++;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	l--;
	ll tot0,tot1;
//	cerr<<calc(0,2,1)<<endl;
	tot0=((r+1)>>2)-((l-1+1)>>2); if (l==0) tot0++;
	tot1=((r+3)>>2)-((l-1+3)>>2);
	ll mn0=l; while (mn0%4!=0||mn0==0) mn0++;
	ll mx0=r; while (mx0%4!=0) mx0--;
	ll mn3=l; while ((mn3+4)%4!=2) mn3++;
	ll mx3=r; while ((mx3+4)%4!=2) mx3--;
	mn3++; mx3++;
	
//	cerr<<calcc(mn0>>2,mx0>>2,mn3>>2,mx3>>2,v>>2)<<endl;
	tot0%=Mod; tot1%=Mod;
	if (v==0) cout<<(calc(tot0)+calc(tot1))%Mod<<endl;
	else if (v==1) cout<<tot0*tot1%Mod<<endl;
	else if (v%4==1) cout<<check(v,mn0^1,mx0^1)*tot1%Mod<<endl;
	else if (v%4==0) cout<<(check(v,mn0,mx0)*tot0+(calcc(mn0>>2,mx0>>2,mn0>>2,mx0>>2,v>>2)+calcc(mn3>>2,mx3>>2,mn3>>2,mx3>>2,v>>2))*inv2)%Mod<<endl;
	else if (v%4==2) cout<<check(v,mn3^1,mx3^1)*tot1%Mod<<endl;
	else if (v%4==3) cout<<(check(v,mn3,mx3)*tot0+calcc(mn0>>2,mx0>>2,mn3>>2,mx3>>2,v>>2))%Mod<<endl;
	else return 3;
	return 0;
}
