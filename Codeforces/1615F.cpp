#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
const int N=2000;
int T,n,f[2100][4100],g[2100][4100]; string s,t;
bool check(const string &s,int i,int x){ return s[i]!=(x^1)+'0';}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while (T--){
		cin>>n>>s>>t;
		for (int i=0;i<n;i++)
			if ((i&1)&&s[i]!='?') s[i]^=1;
		for (int i=0;i<n;i++)
			if ((i&1)&&t[i]!='?') t[i]^=1;
		// cerr<<"s="<<s<<" t="<<t<<'\n';
		for (int i=0;i<=n;i++)
			for (int j=-i;j<=i;j++){
				f[i][j+N]=0;
				g[i][j+N]=0;
			}
		f[0][0+N]=1; g[0][0+N]=0;
		for (int i=0;i<n;i++){
			for (int j=-i;j<=i;j++)
				for (int x=0;x<=1;x++) if (check(s,i,x))
					for (int y=0;y<=1;y++) if (check(t,i,y)){
						int k=j+x-y;
						f[i+1][k+N]=(f[i+1][k+N]+f[i][j+N])%Mod;
						g[i+1][k+N]=(g[i+1][k+N]+g[i][j+N]+1ll*abs(j)*f[i][j+N])%Mod;
					}
			// cerr<<"i="<<i<<'\n';
			// cerr<<"0: "<<f[i][0+N]<<' '<<g[i][0+N]<<'\n';
			// cerr<<"1: "<<f[i][1+N]<<' '<<g[i][1+N]<<'\n';
			// cerr<<"-1: "<<f[i][-1+N]<<' '<<g[i][-1+N]<<'\n';
		}
		cout<<g[n][0+N]<<'\n';
	}
	return 0;
}

