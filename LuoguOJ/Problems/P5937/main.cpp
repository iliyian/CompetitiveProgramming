#include <bits/stdc++.h>
using namespace std;

int pa[10001], v[10001], x[5001], y[5001];
string ops[5001];

int find(int x) {
  return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void merge(int x, int y) {
  pa[find(x)] = find(y);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m, vcnt = 0;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i] >> ops[i];
    x[i]--;
    v[vcnt++] = x[i];
    v[vcnt++] = y[i];
  };
  sort(v, v + vcnt);
  int len = unique(v, v + vcnt) - v;

  for (int i = 1; i <= len << 1; i++)
    pa[i] = i;

  for (int i = 0; i < m; i++) {
    int xi = lower_bound(v, v + len, x[i]) - v + 1,
      yi = lower_bound(v, v + len, y[i]) - v + 1;
    if (ops[i] == "even") {
      if (find(xi) == find(yi + len)) {
        cout << i << '\n';
        return 0;
      } else {
        merge(xi, yi);
        merge(xi + len, yi + len);
      }
    } else {
      if (find(xi) == find(yi)) {
        cout << i << '\n';
        return 0;
      } else {
        merge(xi, yi + len);
        merge(xi + len, yi);
      }
    }
  }
  cout << m;
  return 0;
}