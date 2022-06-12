#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int T,a[310];
int main(){
	scanf("%d",&T);
	while (T--){
		int mn=INF,mx=-INF;
		double ave=0,var=0;
		for (int i=1;i<=250;i++){
			scanf("%d",&a[i]);
			ave+=a[i]; mn=min(mn,a[i]); mx=max(mx,a[i]);
		}
		ave/=250;
		for (int i=1;i<=250;i++) var+=(a[i]-ave)*(a[i]-ave);
		var/=250;
		if (var*3/ave/ave<0.6) printf("%.0lf\n",ave);
		else printf("%.0lf\n",(mn+mx)/2.0);
	}
	return 0;
}
