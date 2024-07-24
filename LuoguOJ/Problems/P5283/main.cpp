// date: 2024-07-24 11:30:38
// tag: 01trie上二分，贪心

#include <bits/stdc++.h>
#define int long long
#define N ((int)5e5 + 5)
// using namespace std;

std::vector<std::array<int, 2>> trie(N << 4);
std::vector<int> cnt(N << 5);
int tot = 0;

void insert(int x) {
  int cur = 0;
  for (int i = 31; i >= 0; i--) {
    int idx = x >> i & 1;
    if (!trie[cur][idx]) trie[cur][idx] = ++tot;
    cur = trie[cur][idx];
    cnt[cur]++;
  }
}

int query(int x, int k) {
  int cur = 0, ans = 0;
  for (int i = 31; i >= 0; i--) {
    int idx = x >> i & 1;
    if (cnt[trie[cur][idx]] >= k) cur = trie[cur][idx];
    else {
      k -= cnt[trie[cur][idx]];
      cur = trie[cur][idx ^ 1];
      ans ^= 1ll << i;
    }
  }
  return ans;
}

struct Node {
  int id, rnk, v;
  bool operator < (const Node &b) const {
    return v < b.v;
  }
};

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  insert(0);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] ^= a[i - 1];
    insert(a[i]);
  }
  std::priority_queue<Node> q;
  for (int i = 0; i <= n; i++) {
    q.push({i, n + 1, query(a[i], n + 1)});
  }
  k *= 2;
  int ans = 0;
  while (k--) {
    auto u = q.top(); q.pop();
    ans += u.v;
    if (u.rnk) {
      q.push({u.id, u.rnk - 1, query(a[u.id], u.rnk - 1)});
    }
  }
  std::cout << ans / 2 << '\n';
  return 0;
}