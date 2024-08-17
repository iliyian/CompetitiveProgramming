#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 1e5 + 5;

std::vector<std::array<int, 2>> trie(N << 4);
std::vector<int> cnt(N << 4);
int tot = 1;

void insert(int x, int c) {
  int cur = 1;
  for (int i = 7; i >= 0; i--) {
    int idx = x >> i & 1;
    if (!trie[cur][idx]) trie[cur][idx] = ++tot;
    cur = trie[cur][idx];
    cnt[cur] += c;
  }
}

int query(int x) {
  int cur = 1, ans = 0;
  for (int i = 7; i >= 0; i--) {
    int idx = x >> i & 1;
    if (cnt[trie[cur][idx ^ 1]]) {
      ans += 1 << i;
      cur = trie[cur][idx ^ 1];
    } else {
      cur = trie[cur][idx];
    }
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] ^= a[i - 1];
    insert(a[i], 1);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = std::max(ans, query(a[i]));
  }
  for (int i = 1; i <= n; i++) {
    insert(a[i], -1);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);


  insert(0, 1);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}