#include<bits/stdc++.h>
using namespace std;
const int N=110000;
const int INF=0x3f3f3f3f;
class SplayTree{
private:
    int rt,top,st[N],tot; int val[N];
    int fa[N],ch[N][2];
    int sz[N],cnt[N];
    int dir(int x){ return ch[fa[x]][1]==x;}
    void pushup(int x){
        sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+cnt[x];
    }
    int newnode(int x,int c){
        int y=(top?st[top--]:++tot);
        fa[y]=x; if (x) ch[x][c>val[x]]=y;
        sz[y]=1; cnt[y]=1; val[y]=c; ch[y][0]=ch[y][1]=0;
        return y;
    }
    void rotate(int x){
        int y=fa[x],z=fa[y],k=dir(x);
        fa[x]=z; if (z) ch[z][dir(y)]=x;
        ch[y][k]=ch[x][!k]; if (ch[x][!k]) fa[ch[x][!k]]=y;
        ch[x][!k]=y; fa[y]=x;
        pushup(y); pushup(x);
    }
    void splay(int x,int g=0){
        while (fa[x]!=g){
            int y=fa[x],z=fa[y];
            if (z!=g) rotate(dir(y)==dir(x)?y:x);
            rotate(x);
        }
        if (!g) rt=x;
    }
    int adj(int x,int k){//k=0 -> pre, k=1 -> nxt
        splay(x); x=ch[x][k];
        while (ch[x][!k]) x=ch[x][!k];
        splay(x); return x;//x exists
    }
public:
	SplayTree(){
		tot=0;
		Ins(-INF); Ins(INF);
	}
    int Ins(int c){
        int x=rt,y=0;
        while (x&&val[x]!=c) y=x,x=ch[x][c>val[x]];
        if (x) cnt[x]++;
        else x=newnode(y,c);
        splay(x); return x;
    }
    int Find(int c){//c exists
        int x=rt;
        while (x&&val[x]!=c) x=ch[x][c>val[x]];
        splay(x); return x;
    }
    void Del(int c){//c exists
        int x=Find(c);
        if (cnt[x]>1){ cnt[x]--; return;}

        int pre=adj(x,0),nxt=adj(x,1);
        splay(pre,nxt); fa[x]=0; ch[pre][1]=0;
        st[++top]=x; splay(pre);
    }
    
    int Rank(int c){//c exists
        int x=Find(c);
        return sz[ch[x][0]];//+1
    }
    int Kth(int k){
        int x=rt; k++;
        if (sz[x]<=k) return 0;

        while (true)
            if (k<=sz[ch[x][0]]) x=ch[x][0];
            else{
                k-=sz[ch[x][0]];
                if (k<=cnt[x]) break;
                else k-=cnt[x],x=ch[x][1];
            }
        splay(x); return val[x];
    }
    
    int Adj(int c,int k){// k=0 -> pre, k=1 -> nxt
    	int res=val[adj(Ins(c),k)];
    	Del(c); return res;
	}
} T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int Q; cin>>Q;
    int op,c;
    while (Q--){
        cin>>op>>c;
        if (op==1){ T.Ins(c); continue;}
        if (op==2){ T.Del(c); continue;}
        if (op==3){ cout<<T.Rank(c)<<'\n'; continue;}
        if (op==4){ cout<<T.Kth(c)<<'\n'; continue;}
        if (op==5){ cout<<T.Adj(c,0)<<'\n'; continue;}
        if (op==6){ cout<<T.Adj(c,1)<<'\n'; continue;}
        throw "No such operation!";
    }
    return 0;
}
