#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int n,T;
int main(){
	scanf("%d%d",&n,&T); int ans=0,x;
	for (int i=1;i<T&&i<=n;i++){
		scanf("%d",&x); q.push(max(x-i,0));
		while (!q.empty()&&q.top()>=T-i) q.pop();
		ans=max(ans,(int)q.size());
	}
	printf("%d\n",ans);
	return 0;
}