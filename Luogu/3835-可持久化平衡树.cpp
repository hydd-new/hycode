#include<bits/stdc++.h>
using namespace std;
const int N=30000000;
const int INF=INT_MAX;
typedef pair<int,int> pii;
int n,rt[510000];
struct Treap{
	int cnt,val[N],sz[N],ch[N][2];
	int Newnode(int c){
		cnt++;
		val[cnt]=c; sz[cnt]=1;
		ch[cnt][0]=ch[cnt][1]=0;
		return cnt;
	}
	int Copy(int u){
		cnt++;
		val[cnt]=val[u]; sz[cnt]=sz[u];
		ch[cnt][0]=ch[u][0]; ch[cnt][1]=ch[u][1];
		return cnt;
	}
	void pushup(int u){
		sz[u]=sz[ch[u][0]]+sz[ch[u][1]]+1;
	}
	pii Split(int x,int k){
		if (!x) return pii(0,0);
		if (k<=sz[ch[x][0]]){
			pii t=Split(ch[x][0],k);
			
			int u=Copy(x);
			ch[u][0]=t.second; pushup(u);
			return pii(t.first,u);
		} else{
			pii t=Split(ch[x][1],k-sz[ch[x][0]]-1);
			
			int u=Copy(x);
			ch[u][1]=t.first; pushup(u);
			return pii(u,t.second);
		}
	}
	int Merge(int x,int y){
		if (!x||!y) return x|y;
		if (rand()%(sz[x]+sz[y])<sz[x]){
			int u=Copy(x);
			ch[u][1]=Merge(ch[u][1],y); pushup(u); 
			return u;
		} else{
			int u=Copy(y);
			ch[u][0]=Merge(x,ch[u][0]); pushup(u);
			return u;
		}
	}
	int Rank(int x,int c){
		if (!x) return 0;
		if (val[x]>=c) return Rank(ch[x][0],c);
		else return Rank(ch[x][1],c)+sz[ch[x][0]]+1;
	}
	int Rank2(int x,int c){
		if (!x) return 0;
		if (val[x]>c) return Rank2(ch[x][0],c);
		else return Rank2(ch[x][1],c)+sz[ch[x][0]]+1;
	}
	int Kth(int x,int k){
		if (k<=sz[ch[x][0]]) return Kth(ch[x][0],k);
		else if (k==sz[ch[x][0]]+1) return val[x];
		else return Kth(ch[x][1],k-sz[ch[x][0]]-1);
	}
	int Ins(int x,int c){
		pii t=Split(x,Rank(x,c));
		return Merge(Merge(t.first,Newnode(c)),t.second);
	}
	int Del(int x,int c){
		if (Rank(x,c)==Rank2(x,c)) return x; 
		pii a=Split(x,Rank(x,c));
		pii b=Split(a.second,1);
		return Merge(a.first,b.second);
	}
	int Pre(int x,int c){ return Kth(x,Rank(x,c));}
	int Nxt(int x,int c){ return Kth(x,Rank2(x,c)+1);}
	void print(int x){
		if (!x) return;
		print(ch[x][0]);
		if (abs(val[x])<=1000000000) cout<<val[x]<<' ';
		print(ch[x][1]);
	}
} T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	srand(time(NULL));
	cin>>n; int v,op,x;
	rt[0]=T.Merge(T.Newnode(-INF),T.Newnode(INF));
	for (int i=1;i<=n;i++){
		cin>>v>>op>>x;
		if (op==1) rt[i]=T.Ins(rt[v],x);
		else if (op==2) rt[i]=T.Del(rt[v],x);
		else if (op==3) rt[i]=rt[v],cout<<T.Rank(rt[i],x)<<'\n';
		else if (op==4) rt[i]=rt[v],cout<<T.Kth(rt[i],x+1)<<'\n';
		else if (op==5) rt[i]=rt[v],cout<<T.Pre(rt[i],x)<<'\n';
		else rt[i]=rt[v],cout<<T.Nxt(rt[i],x)<<'\n';
		
//		T.print(rt[i]); cout<<'\n';
	}
	return 0;
}

