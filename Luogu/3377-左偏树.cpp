#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m;
struct Leftist_Tree{
	int bel[210000],ls[210000],rs[210000],val[210000],d[210000];
	int Find(int x){
		if (x!=bel[x]) bel[x]=Find(bel[x]);
		return bel[x];
	}
	void Pop(int x){
		val[x]=-1;
		bel[ls[x]]=ls[x]; bel[rs[x]]=rs[x];
		bel[x]=Merge(ls[x],rs[x]);
	}
	int Merge(int x,int y){
		if (!x||!y) return x|y;
		if (pii(val[x],x)>pii(val[y],y)) swap(x,y);
		
		rs[x]=Merge(rs[x],y);
		if (d[ls[x]]<d[rs[x]]) swap(ls[x],rs[x]);
		bel[ls[x]]=bel[rs[x]]=x;
		d[x]=d[rs[x]]+1; return x;
	}
} T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m; T.d[0]=-1;
	for (int i=1;i<=n;i++){
		T.bel[i]=i;
		cin>>T.val[i];
	}
	int op,x,y;
	for (int i=1;i<=m;i++){
		cin>>op>>x;
		if (op==1){
			cin>>y;
			if (T.val[x]==-1||T.val[y]==-1) continue;
			x=T.Find(x); y=T.Find(y);
			if (x!=y) T.Merge(x,y);
		} else{
			if (T.val[x]==-1) cout<<"-1\n";
			else{
				x=T.Find(x);
				cout<<T.val[x]<<'\n'; T.Pop(x);
			}
		}
	}
	return 0;
}

