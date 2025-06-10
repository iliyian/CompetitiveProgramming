#include <bits/stdc++.h>
#define int long long

int get(int l1, int r1, int l2, int r2, int s2, int t2, int len) {
  if (l2 > t2 || r2 < s2) return 0;
  if (l2 <= s2 && t2 <= r2) {
    int a = (t2 - s2 + 1);
    return std::max(a, len) / std::min(a, len);
  }
  int mid2 = (s2 + t2) / 2;
  return get(l1, r1, l2, r2, s2, mid2, len) + get(l1, r1, l2, r2, mid2 + 1, t2, len);
}

int query(int l1, int r1, int l2, int r2, int s1, int t1) {
  if (l1 > t1 || r1 < s1) return 0;
  if (l1 <= s1 && t1 <= r1) {
    return get(l1, r1, l2, r2, 0, 1048575, t1 - s1 + 1);
  }
  int mid1 = (s1 + t1) / 2;
  return query(l1, r1, l2, r2, s1, mid1) + query(l1, r1, l2, r2, mid1 + 1, t1);
};

void solve() {
  int l1, r1, l2, r2;
  std::cin >> l1 >> r1 >> l2 >> r2;
  r1--, r2--;
  std::cout << query(l1, r1, l2, r2, 0, 1048575) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}