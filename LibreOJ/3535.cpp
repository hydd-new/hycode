#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int n,m,ans,k,p[256],a[400005][16],b[16],popc[110000]; ull a1,a2;
bool s[256]; string t;
vector<pii> vec[25];
ull myRand(ull &k1,ull &k2){
	ull k3=k1,k4=k2;
	k1=k4;
	k3^=(k3<<23);
	k2=k3^k4^(k3>>17)^(k4>>26);
	return k2+k4;
}
void gen(int n,ull a1,ull a2){
	for (int i=1;i<=n;i++){
		for (int j=0;j<256;j++){
			s[j]=(myRand(a1,a2)&(1ull<<32))?1:0;
//			cout<<s[j];
		}
//		cout<<'\n';
		int now=0;
		for (int j=0;j<256;j+=16){
			for (int k=0;k<16;k++)
				a[i][now]=(a[i][now]<<1)|s[p[j+k]];
			vec[now].push_back(pii(a[i][now],i));
			now++;
		}
	}
	for (int k=0;k<16;k++) sort(vec[k].begin(),vec[k].end());
}
inline void check(int x){
	if (popc[a[x][0]^b[0]]+popc[a[x][1]^b[1]]+popc[a[x][2]^b[2]]+popc[a[x][3]^b[3]]+
		popc[a[x][4]^b[4]]+popc[a[x][5]^b[5]]+popc[a[x][6]^b[6]]+popc[a[x][7]^b[7]]+
		popc[a[x][8]^b[8]]+popc[a[x][9]^b[9]]+popc[a[x][10]^b[10]]+popc[a[x][11]^b[11]]+
		popc[a[x][12]^b[12]]+popc[a[x][13]^b[13]]+popc[a[x][14]^b[14]]+popc[a[x][15]^b[15]]<=k) ans=true;
}
int main(){
	freopen("qi.in","r",stdin);
	freopen("qi.out","w",stdout);
	srand(19260817);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i=0;i<65536;i++) popc[i]=popc[i>>1]+(i&1);
	for (int i=0;i<256;i++) p[i]=i;
	random_shuffle(p,p+256);
	cin>>n>>m>>a1>>a2;
	gen(n,a1,a2); ans=0;
	for (int i=1;i<=m;i++){
		cin>>t>>k; int loc=0;
		for (int j=0;j<256;j+=4){
			for (int k=0;k<4;k++)
				s[j+k]=((t[loc]>='A'?t[loc]-'A'+10:t[loc]-'0')>>(3-k))&1;
			loc++;
		}
		if (ans)
			for (int j=0;j<256;j++) s[j]^=1;
		ans=0;
//		for (int j=0;j<256;j++) cout<<s[j]; cout<<'\n';
		int now=0;
		for (int j=0;j<256;j+=16){
			b[now]=0;
			for (int k=0;k<16;k++)
				b[now]=(b[now]<<1)|s[p[j+k]];
			now++;
		}
		for (int i=0;i<16&&!ans;i++){
			int pos=lower_bound(vec[i].begin(),vec[i].end(),pii(b[i],0))-vec[i].begin();
			while (pos<(int)vec[i].size()&&vec[i][pos].first==b[i]&&!ans) check(vec[i][pos].second),pos++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}