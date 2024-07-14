#include <bits/stdc++.h>
// #define int long long
// using namespace std;

constexpr int N = 4e7;

std::vector<std::array<int, 2>> trie(N + 1);
std::vector<int> sz(N + 1);
int tot = 1;

void insert(int x, int c) {
  int u = 1;
  for (int i = 30; i >= 0; i--) {
    int idx = x >> i & 1;
    sz[u] += c;
    if (!trie[u][idx]) trie[u][idx] = ++tot;
    u = trie[u][idx];
  }
  sz[u] += c;
}

int kth(int k) {
  int u = 1, ans = 0;
  for (int i = 30; i >= 0; i--) {
    if (k <= sz[trie[u][0]]) {
      u = trie[u][0];
    } else {
      k -= sz[trie[u][0]];
      u = trie[u][1];
      ans ^= 1 << i;
    }
  }
  return ans;
}

int rnk(int x) {
  int ans = 0, u = 1;
  for (int i = 30; i >= 0; i--) {
    if (x >> i & 1) {
      ans += sz[trie[u][0]];
      u = trie[u][1];
    } else {
      u = trie[u][0];
    }
  }
  return ans;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    insert(x, 1);
  }
  int last = 0, ans = 0;
  for (int i = 1; i <= m; i++) {
    int op, x;
    std::cin >> op >> x;
    x ^= last;
    if (op == 1) {
      insert(x, 1);
    } else if (op == 2) {
      insert(x, -1);
    } else if (op == 3) {
      last = rnk(x) + 1;
    } else if (op == 4) {
      last = kth(x);
    } else if (op == 5) {
      last = kth(rnk(x));
    } else if (op == 6) {
      last = kth(rnk(x + 1) + 1);
    }
    if (3 <= op && op <= 6) {
      ans ^= last;
    }
  }
  std::cout << ans << '\n';

  return 0;
}