#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,q,cnt,k[210000],pos[210000],ans[210000];
int fa[210000],fail[210000],ch[210000][26];
string s;
vector<int> vec[210000];
vector<pii> Q[210000];
int ins(const string &s){
	int n=s.length(),u=0;
	for (int i=0;i<n;i++){
		int c=s[i]-'a';
		if (!ch[u][c]) ch[u][c]=++cnt;
		fa[ch[u][c]]=u; u=ch[u][c];
	}
	return u;
}

int dtime,dfn[210000],sz[210000];

void dfs(int u){
	dfn[u]=++dtime; sz[u]=1;
	for (int v:vec[u]){
		dfs(v);
		sz[u]+=sz[v];
	}
}

queue<int> que;
void build(){
    for (int i=0;i<26;i++)
        if (ch[0][i]) que.push(ch[0][i]);
	while (!que.empty()){
		int u=que.front(); que.pop();
		for (int i=0;i<26;i++)
			if (ch[u][i]){ fail[ch[u][i]]=ch[fail[u]][i]; que.push(ch[u][i]);}
			else ch[u][i]=ch[fail[u]][i];
	}
	for (int i=1;i<=cnt;i++) vec[fail[i]].push_back(i);
	dfs(0);
}

int tree[210000];
void add(int x,int y){
	for (;x<=cnt+1;x+=x&-x) tree[x]+=y;
}
int query(int x){
	int res=0;
	for (;x;x-=x&-x) res+=tree[x];
	return res;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s;
		pos[i]=ins(s);
	}
	build();
	int l,r;
	for (int i=1;i<=q;i++){
		cin>>l>>r>>k[i];
		Q[l-1].push_back(pii(i,-1)); Q[r].push_back(pii(i,1));
	}
	for (int i=1;i<=n;i++){
		int u=pos[i];
		while (u) add(dfn[u],1),u=fa[u]; add(dfn[0],1);
		for (pii u:Q[i]){
			int x=pos[k[u.first]];
			ans[u.first]+=(query(dfn[x]+sz[x]-1)-query(dfn[x]-1))*u.second;
		}
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
