#include <bits/stdc++.h>
#define N 1005
using namespace std;

int pa[N << 1];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}
void merge(int x, int y) {pa[find(x)] = find(y);}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  iota(pa + 1, pa + 1 + n * 2, 1);
  for (int i = 0; i < m; i++) {
    int r, a, b;
    cin >> r >> a >> b;
    if (r) {
      merge(b + n, a);
      merge(a + n, b);
    } else {
      merge(a, b);
      // merge(a + n, b + n);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += pa[i] == i;
  cout << ans;
  return 0;
}