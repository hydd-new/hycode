#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
    scanf("%d%d",&a,&b);
    if (a>0) puts("Positive");
    else if (b<0) puts((b-a)&1?"Positive":"Negative");
    else puts("Zero");
    return 0;
}