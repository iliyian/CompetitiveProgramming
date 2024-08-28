// date: 2024-08-28 13:00:24
// tag: 01trie，异或集合最值查询

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 2e5;

std::vector<std::array<int, 2>> tr(N << 2);
std::vector<int> cnt(N << 2);
int tot = 0;

void insert(int x, int c) {
  int u = 0;
  for (int i = 20; i >= 0; i--) {
    int idx = x >> i & 1;
    if (!tr[u][idx]) tr[u][idx] = ++tot;
    u = tr[u][idx];
    cnt[u] += c;
  }
}

int querymx(int x) {
  int u = 0, ans = 0;
  for (int i = 20; i >= 0; i--) {
    int idx = x >> i & 1;
    if (cnt[tr[u][idx ^ 1]]) {
      u = tr[u][idx ^ 1];
      ans += 1 << i;
    } else {
      u = tr[u][idx];
    }
  }
  return ans;
}

int querymn(int x) {
  int u = 0, ans = 0;
  for (int i = 20; i >= 0; i--) {
    int idx = x >> i & 1;
    if (cnt[tr[u][idx]]) {
      u = tr[u][idx];
    } else {
      u = tr[u][idx ^ 1];
      ans += 1 << i;
    }
  }
  return ans;
}

void solve() {
  int l, r;
  std::cin >> l >> r;
  int len = r - l + 1;
  std::vector<int> a(len + 1);
  for (int i = 1; i <= len; i++) {
    std::cin >> a[i];
    insert(a[i], 1);
  }
  for (int i = 1; i <= len; i++) {
    int x = a[i] ^ l;
    if (querymx(x) == r && querymn(x) == l) {
      std::cout << x << '\n';
      break;
    }
  }
  for (int i = 1; i <= len; i++) {
    insert(a[i], -1);
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D2.in", "r", stdin);
  freopen("D2.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}