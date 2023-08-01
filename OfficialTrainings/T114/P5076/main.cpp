#include <bits/stdc++.h>
using namespace std;

multiset<int> s;

int val[10001], cnt[10001], siz[10001], lc[10001], rc[10001];

int queryrnk(int o, int v) {
  if (val[o] == v) return siz[lc[o]] + 1;
  if (val[o] < v) return queryrnk(rc[o], v);
  if (val[o] < v) return queryrnk(lc[o], v);
}

int querykth(int o, int k) {
  if (siz[lc[o]] >= k) return querykth(lc[o], k);
  if (siz[lc[o]] < k - cnt[o]) return querykth(rc[o], k - cnt[o] - siz[lc[o]]);
  return val[o];
}

void insert(int o, int v) {
  if (!o) {
    cnt[o]++;
    val[o] = v;
    lc[o] = rc[o];
  }
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int op, x;
    cin >> op >> x;
    switch (op) {
      case 1:
        cout << queryrnk(0, x) << '\n';
      break;
      case 2:
        cout << querykth(0, x) << '\n';
      break;
      case 3:
      break;
      case 4:
      break;
      case 5:
        insert(0, x);
      break;
    }
  }
}