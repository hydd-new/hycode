#include<bits/stdc++.h>
using namespace std;
int n,k,p[210000];
int L[210000],R[210000],len[210000];
int head,tail,que[210000];
int main(){
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&p[i]);
    head=1; tail=0;
    for (int i=0;i<n;i++){
        while (head<=tail&&que[head]<=i-k) head++;
        while (head<=tail&&p[que[tail]]<p[i]) tail--;
        R[i]=(head>tail); que[++tail]=i;
    }
    head=1; tail=0;
    for (int i=n-1;i>=0;i--){
        while (head<=tail&&que[head]>=i+k) head++;
        while (head<=tail&&p[que[tail]]>p[i]) tail--;
        L[i]=(head>tail); que[++tail]=i;
    }
    for (int i=n-1;i>=0;i--)
    	if (p[i]<p[i+1]) len[i]=len[i+1]+1;
    	else len[i]=1;
    int ans=0; bool flag=false;
    for (int i=0;i+k-1<n;i++)
        if (len[i]>=k) flag=true;
        else ans+=!(L[i]&&R[i+k]);
    printf("%d\n",ans+flag);
    return 0;
}
