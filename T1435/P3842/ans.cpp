#include <iostream>
#include <cstdio>
#define rep(i,m,n) for(int i=m;i<=n;++i)
using namespace std;
inline int read(){
    int s = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}
const int MAXN = 20010;
int n;
int l[MAXN], r[MAXN], f[MAXN][2];
int main(){
  freopen("data.in", "r", stdin);
    n = read();
    rep(i, 1, n) l[i] = read(), r[i] = read();
    f[1][0] = r[1] + r[1] - l[1] - 1;
    f[1][1] = r[1] - 1;
    rep(i, 2, n)
       f[i][0] = min(f[i-1][0] + abs(l[i-1] - r[i]) + r[i] - l[i] + 1, f[i-1][1] + abs(r[i-1] - r[i]) + r[i] - l[i] + 1),
       f[i][1] = min(f[i-1][0] + abs(l[i-1] - l[i]) + r[i] - l[i] + 1, f[i-1][1] + abs(r[i-1] - l[i]) + r[i] - l[i] + 1);
    printf("%d\n", min(f[n][0] + n - l[n], f[n][1] + n - r[n]));
    //rep(i, 1, n){ rep(j, 0, 1) printf("f[%d][%d] = %d, ", i, j, f[i][j]); puts(""); }
    return 0;
}