#include<bits/stdc++.h>
using namespace std;
int n,l,t,x[110000],w[110000];
int main(){
    scanf("%d%d%d",&n,&l,&t);
    int pos=0,d;
    for (int i=0;i<n;i++){
        scanf("%d%d",&x[i],&w[i]);
        if (w[i]==1) x[i]+=t,d=x[i]/l;
        else x[i]-=t,d=(x[i]-l+1)/l;
        pos=(pos+d)%n; x[i]-=l*d;
    }
    sort(x,x+n); pos=(pos+n)%n;
    for (int i=0;i<n;i++) printf("%d\n",x[(i+pos)%n]);
    return 0;
}