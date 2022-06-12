//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
struct S{
	int l,r,v;
};
S sta[1919810];
int cnt,n,len[200002];
inline void merge(){
	while(cnt>1&&sta[cnt].v==sta[cnt-1].v){
		--cnt;
		sta[cnt].r=sta[cnt+1].r;
	}
	while(cnt>2&&sta[cnt-1].v==sta[cnt-2].v){
		sta[cnt-2].r=sta[cnt-1].r;
		sta[cnt-1]=sta[cnt];
		--cnt;
	}
}
int TOT;
inline int cut(int pos){
	UF(i,cnt,1){
		if(sta[i].l==pos){
			return i;
		}
		if(sta[i].r==pos){
			++cnt;
			UF(ii,cnt,i+1)sta[ii]=sta[ii-1];
			sta[i+1].l=pos;
			sta[i].r=pos-1;
			return i+1;
		}
	}
	return 114514;
}
bool check(int tot){TOT=tot;
	cnt=0;
	F(i,1,n){
		if(len[i]>sta[cnt].r){
			++cnt;
			sta[cnt]=S{sta[cnt-1].r+1,len[i],1};
		}else{
			while(sta[cnt].l>len[i])--cnt;
			sta[cnt].r=len[i];
			if(sta[cnt].v==tot){merge();
				if(sta[cnt].l==1)return 0;//if(sta[cnt-1].v==sta[cnt].v||sta[cnt-1].r!=sta[cnt].l-1)while(1);
				int qwq=cut(sta[cnt].l-1);
				++sta[qwq].v;
				//if(sta[qwq].v>tot&&sta[cnt].v==tot&&qwq==cnt-1)exit(1919810);
				//if(qwq!=cnt-1)while(1);
				sta[cnt].v=1;
			}else{
				cut(sta[cnt].r);
				++sta[cnt].v;
			}
		}
		merge();//if(tot==2)cerr<<i<<endl;
	}
	return 1;
}
int main() {
	freopen("C.in","r",stdin);
	cin>>n;
	F(i,1,n)read(len[i]);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}
