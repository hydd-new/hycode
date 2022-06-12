#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s; char now=0;
	for (char c:s){
		while (now!=c){
			cout<<"..\nX.\n";
			now--;
		}
		cout<<"X.\n";
	}
	return 0;
}