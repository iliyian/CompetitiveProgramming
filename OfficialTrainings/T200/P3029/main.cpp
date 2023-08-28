#include <bits/stdc++.h>
using namespace std;

map<int, int> a;
int n, mind = 1 << 30, maxd = -1;;
set<int> s, k;

bool check(int len) {
  for (int l = mind; l < maxd - len; l++) {
    k.clear();
    for (int j = l; j <= l + len; j++)
      if (a[j])
        k.insert(a[j]);
    if (k.size() == s.size()) {
      return true;
    }
  }
  return false;
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; i++)  {
    int x, id;
    cin >> x >> id;
    a[x] = id;
    mind = min(mind, x);
    maxd = max(maxd, x);
    s.insert(id);
  }
  int ans = -1, l = 1, r = maxd - mind;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  if (ans == -1) cout << r;
  else cout << ans;
  return 0;
}