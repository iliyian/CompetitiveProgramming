#include <bits/stdc++.h>
#define N 100001
using namespace std;

int a[N], d[N * 4], n, q, m;

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = a[s];
    return;
  }
  int mid = s + ((t - s) >> 1);
  build(s, mid, p << 1);
  build(mid + 1, t, p << 1 | 1);
  d[p] = d[p << 1] + d[p << 1 | 1];
}

struct Lazy {
  int mul = 1, add = 0;
};
Lazy b[N * 4];

void cal();

void maintain(int s, int t, int p) {
  int mid = s + ((t - s) >> 1);
  d[p << 1];
}

int getSum(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p] % m;
  int mid = s + ((t - s) >> 1);

}

int main() {
  cin >> n >> q >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 1);
  for (int i = 0; i < q; i++) {
    int op, x, y, k;
    cin >> op >> x >> y;
    if (op == 1) {
      cin >> k;
    } else if (op == 2) {

    } else {
      cout << getSum(x, y, 1, n, 1);
    }
  }
}