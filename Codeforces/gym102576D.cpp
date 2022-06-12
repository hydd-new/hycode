#include<bits/stdc++.h>
using namespace std;
int T,n,l[3100],r[3100];
struct node{
    int x,y,op;
    node(){}
    node(int _x,int _y,int _op):x(_x),y(_y),op(_op){}
    bool operator<(const node &a) const{ return x<a.x||x==a.x&&op<a.op;}
} a[3100];
multiset<int> s;
multiset<int>::iterator it;
int calc(int l,int r){//clockwise
    if (l>r) r+=1000000;
    return r-l;
}
bool iscontain(int l,int r,int x){
    if (l<=r) return (l<=x&&x<=r);
    else return (l<=x||x<=r);
}
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
        int ans=0;
        for (int i=1;i<=n;i++){
            int res=0,tot=0;
            for (int j=1;j<=n;j++){
            	bool flg1=iscontain(l[j],r[j],l[i]),flg2=iscontain(l[j],r[j],r[i]);
                if (flg1&&flg2){ res++; continue;}
                if (flg1) a[++tot]=node(calc(l[i],r[j]),calc(l[j],l[i]),1);
                if (flg2) a[++tot]=node(calc(l[i],l[j]),calc(r[j],l[i]),0),res++;
            }
            sort(a+1,a+tot+1); s.clear();
            for (int j=1;j<=tot;j++){
                if (a[j].op) s.insert(a[j].y);
                else{
                    it=s.lower_bound(a[j].y);
                    if (it!=s.begin()) s.erase(--it);
                }
            }
            ans=max(ans,res+(int)s.size());
        }
        printf("%d\n",ans);
    }
    return 0;
}
