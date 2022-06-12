#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,deg[110000],dep[110000],fa[110000];
vector<int> vec[110000]; bool vis[110000];
priority_queue<pii> que;
void dfs(int u,int f){
    fa[u]=f; dep[u]=dep[f]+1;
    for (int v:vec[u]){
        if (v==f) continue;
        dfs(v,u);
    }
}
int main(){
    cin>>n; int u,v;
    for (int i=1;i<n;i++){
        cin>>u>>v; deg[u]++; deg[v]++;
        vec[u].push_back(v); vec[v].push_back(u);
    }
    deg[1]++; dfs(1,0);
    for (int i=1;i<=n;i++) que.push(pii(dep[i],i));
    while (!que.empty()){
        int u=que.top().second,v=fa[u]; que.pop();
        if (vis[u]) continue;

        deg[v]--; if (deg[v]!=1){ cout<<"First\n"; return 0;}
        vis[v]=true; deg[fa[v]]--;
    }
    cout<<"Second\n";
    return 0;
}
