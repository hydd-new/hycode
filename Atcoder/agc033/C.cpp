#include<bits/stdc++.h>
using namespace std;
int n,rt,dep[210000];
int edgenum,vet[410000],Next[410000],Head[210000];
void addedge(int u,int v){
    vet[++edgenum]=v;
    Next[edgenum]=Head[u];
    Head[u]=edgenum;
}
void dfs(int u,int f){
    dep[u]=dep[f]+1;
    if (dep[u]>dep[rt]) rt=u;
    for (int e=Head[u];e;e=Next[e]){
        if (vet[e]==f) continue;
        dfs(vet[e],u);
    }
}
int main(){
    scanf("%d",&n); int u,v;
    for (int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        addedge(u,v); addedge(v,u);
    }
    dfs(1,0); dfs(rt,0);
    if (dep[rt]%3==2) puts("Second");
    else puts("First");
    return 0;
}