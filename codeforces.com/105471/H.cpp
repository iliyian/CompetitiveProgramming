// fuck wa了，

// date: 2024-11-21 21:06:26
// tag: 一类树形问题，很有意思

#include <bits/stdc++.h>
#define int long long

int n, k;
int a[1 << 20], ans[1 << 20], raw[1 << 20];

void work(int l, int r, int p) {
  if (l + 1 == r) return;
  int mid = (l + r) / 2;
  work(l, mid, p - 1);
  work(mid, r, p - 1);
  int q = 0, j = mid, i = l;
  std::vector<int> b(r - l);
  for (; i < mid; b[q++] = a[i], i++) {
    while (j < r && a[i] > a[j]) {
      int cnt = r - j - 1 + mid - i;
      if (cnt <= k && a[j] >= (1 << p)) {
        ans[a[j]] = std::max(ans[a[j]], p);
      }
      b[q++] = a[j];
      j++;
    }

    int cnt = r - j + mid - 1 - i;
    if (cnt <= k && a[i] >= (1 << p)) {
      ans[a[i]] = std::max(ans[a[i]], p);
    }
  }
  while (j < r) {
    int cnt = r - j - 1;
    if (cnt <= k && a[j] >= (1 << p)) {
      ans[a[j]] = std::max(ans[a[j]], p);
    }
    b[q++] = a[j], j++;
  }
  for (int i = l; i < r; i++) a[i] = b[i - l];
}

void solve() {
  std::cin >> n >> k;
  for (int i = 0; i < (1 << n); i++) {
    std::cin >> a[i];
    raw[i] = a[i];
  }
  std::fill(ans, ans + (1 << n), 0);
  work(0, 1 << n, n);
  for (int i = 0; i < (1 << n); i++) {
    std::cout << ans[raw[i]] << ' ';
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}