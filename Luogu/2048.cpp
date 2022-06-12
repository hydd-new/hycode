#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int n,k,l,r,a[510000],Log2[510000],mx[510000][21];
ll ans;
struct node{
	int now,l,r,x;
	bool operator<(const node &b) const{
		return a[x]-a[now-1]<a[b.x]-a[b.now-1];
	}
};
char Getchar() {
    static char now[1<<16],*S,*T;
    if (T==S) {
        T=(S=now)+fread(now,1,1<<16,stdin);
        if (T==S) return EOF;
    }
    return *S++;
}
int read() {
    int x=0,f=1;
    char ch=Getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=Getchar();
    }
    while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
    return x*f;
}
priority_queue<node> que;
void init(){
	Log2[0]=-1;
    for (int i=1;i<=n;i++) Log2[i]=Log2[i>>1]+1;
    for (int i=1;i<=n;i++) mx[i][0]=i;
    for (int j=1;(1<<j)<=n;j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
            mx[i][j]=(a[mx[i][j-1]] > a[mx[i+(1<<(j-1))][j-1]] ? mx[i][j-1] : mx[i+(1<<(j-1))][j-1]);
}
int query(int L,int R){
    int k=Log2[R-L+1];
    return (a[mx[L][k]] > a[mx[R-(1<<k)+1][k]] ? mx[L][k] : mx[R-(1<<k)+1][k]);
}
int main(){
	n=read(); k=read(); l=read(); r=read();
	for (int i=1;i<=n;i++) a[i]=a[i-1]+read();
	init();
    for (int i=1;i+l-1<=n;i++){
        int R=min(n,i+r-1);
        que.push((node){i,i+l-1,R,query(i+l-1,R)});
    }
    node u;
    while (k--){
    	u=que.top(); que.pop();
    	ans+=a[u.x]-a[u.now-1];
        if (u.x-1>=u.l) que.push((node){u.now,u.l,u.x-1,query(u.l,u.x-1)});
        if (u.x+1<=u.r) que.push((node){u.now,u.x+1,u.r,query(u.x+1,u.r)});
	}
	printf("%lld\n",ans);
	return 0;
}