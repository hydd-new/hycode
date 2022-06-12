#include<cstdio>
#include<algorithm> 
#define ls c[x][0]
#define rs c[x][1]
using namespace std;
int n,m,type,x,y,f[310000],c[310000][2],v[310000],s[310000],st[310000];
bool r[310000];
inline bool nroot(int x){
    return x==c[f[x]][0]||x==c[f[x]][1];
}
inline void pushup(int x){
    s[x]=s[ls]^s[rs]^v[x];
}
inline void pushr(int x){
    swap(ls,rs);
    r[x]^=1;
}
inline void pushdown(int x){
    if (r[x]){
        if (ls) pushr(ls);
        if (rs) pushr(rs);
        r[x]=0;
    }
}
inline int dir(int x){ return c[f[x]][1]==x;}
void rotate(int x){
    int y=f[x],z=f[y],k=dir(x),w=c[x][!k];
    if (nroot(y)) c[z][dir(y)]=x;
    c[x][!k]=y; c[y][k]=w;
    if (w) f[w]=y; 
    f[y]=x; f[x]=z;
    pushup(y);
}
void splay(int x){
    int y=x,z=0;
    st[++z]=y;
    while (nroot(y)) st[++z]=y=f[y];
    while (z) pushdown(st[z--]);
    while (nroot(x)){
        y=f[x];
        if (nroot(y)) rotate(dir(x)!=dir(y)?x:y);
        rotate(x);
    }
    pushup(x);
}
void access(int x){
    for (int y=0;x;y=x,x=f[y]){//注意此处，x是打通到整棵树的根的路径，所以是;x;而不是;nroot(x);。
        splay(x);
        rs=y; pushup(x);
    } 
}
inline void makeroot(int x){ access(x); splay(x); pushr(x);}
int findroot(int x){
    access(x); splay(x);
    while (ls){
        pushdown(x); x=ls;
    }
    splay(x);
    return x;
}
inline void split(int x,int y){ makeroot(x); access(y); splay(y);}
void link(int x,int y){
    makeroot(x);
    if (findroot(y)!=x) f[x]=y;
}
void cut(int x,int y){
    makeroot(x);
    if (findroot(y)==x&&f[y]==x&&!c[y][0]){
        f[y]=0; c[x][1]=0;
        pushup(x);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&v[i]);
    while (m--){
        scanf("%d%d%d",&type,&x,&y);
        switch (type){
            case 0: split(x,y); printf("%d\n",s[y]); break;
            case 1: link(x,y); break;
            case 2: cut(x,y); break;
            case 3: splay(x); v[x]=y; break;
        }
    }
    return 0;
}