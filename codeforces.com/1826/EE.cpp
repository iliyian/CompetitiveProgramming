#include <bits/stdc++.h>
#define FL(i, a, b) for(int i = (a); i <= (b); i++)
#define FR(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 5010, M = 510;
int m, n, c, r[N][M], id[N];
ll ans, f[N];
bitset<N> now, b[N];
int cmp(int i, int j){return r[i][c] < r[j][c];}
int main(){
  freopen("E.in", "r", stdin);
	scanf("%d%d", &m, &n);
	FL(i, 1, n) id[i] = i, b[i].set();
	FL(j, 0, m) FL(i, 1, n) scanf("%d", &r[i][j]);
	FL(k, 1, m){
		now.reset(), now[0] = 1, c = k;
		sort(id + 1, id + n + 1, cmp);
		FL(i, 1, n){
			int j = i;
			while(j < n && r[id[j + 1]][k] == r[id[i]][k]) j++;
			FL(l, i, j) b[id[l]] &= now;
			FL(l, i, j) now[id[l]] = 1; i = j;
		}
	}
	sort(id + 1, id + n + 1, cmp);
	FL(i, 1, n) FL(j, 0, i - 1) if(b[id[i]][id[j]])
		f[i] = max(f[i], f[j] + r[id[i]][0]);
	FL(i, 1, n) ans = max(ans, f[i]); 
	printf("%lld", ans);
	return 0;
}