#include<bits/stdc++.h>
using namespace std;
int n,a[1100][6],b[1100][6];
int main(){
    // scanf("%d",&n);
    srand(time(NULL));
    n=1000;
    int tot=0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<5;j++) a[i][j]=rand()%100+1;
        sort(a[i],a[i]+5);
        // for (int j=0;j<5;j++) scanf("%d",&a[i][j]);

        if (a[i][0]>26) b[i][4]=0;
        else if (a[i][0]>18) b[i][4]=1;
        else if (a[i][0]>12) b[i][3]=1;
        else if (a[i][0]>7) b[i][2]=1;
        else if (a[i][0]>3) b[i][1]=1;
        else b[i][0]=1;
        for (int j=0;j<5;j++) printf("%d ",b[i][j]); putchar('\n'); fflush(stdout);

        for (int k=1;k<i;k++){
            bool flag=true;
            for (int j=0;j<5;j++){
                if (b[i][j]&&b[k][j]||b[i][j]&&a[i][0]>a[k][0]||b[k][j]&&a[k][0]>a[i][0]){ flag=false; break;}
                if (b[i][j]||b[k][j]){ flag=true; break;}
            }
            if (flag) tot++;
        }
        if (i>1) cerr<<i<<' '<<1.0*tot/(i*(i-1)/2)<<endl;
    }
    return 0;
}
