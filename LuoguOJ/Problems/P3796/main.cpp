// date: 2024-08-17 12:22:18
// tag: AC自动机计算模式串匹配次数

#include <bits/stdc++.h>
// using namespace std;

constexpr int N = 1e6;

std::vector<std::array<int, 26>> tr(N + 1);
std::vector<int> idx(N + 1), fail(N + 1), val(N + 1), cnt(N + 1);
int tot = 0;

void init() {
  for (int i = 0; i <= tot; i++) {
    idx[i] = fail[i] = val[i] = cnt[i] = 0;
    std::fill(tr[i].begin(), tr[i].end(), 0);
  }
  tot = 0;
}

void insert(std::string &str, int i) {
  int p = 0;
  for (char ch : str) {
    if (!tr[p][ch - 'a']) tr[p][ch - 'a'] = ++tot;
    p = tr[p][ch - 'a'];
  }
  idx[p] = i;
}

void build() {
  std::queue<int> q;
  for (int i = 0; i < 26; i++) {
    if (tr[0][i]) {
      q.push(tr[0][i]);
    }
  }
  while (!q.empty()) {
    int p = q.front(); q.pop();
    for (int i = 0; i < 26; i++) {
      if (tr[p][i]) {
        fail[tr[p][i]] = tr[fail[p]][i];
        q.push(tr[p][i]);
      } else {
        tr[p][i] = tr[fail[p]][i];
      }
    }
  }
}

int query(std::string &str) {
  int p = 0;
  for (char ch : str) {
    p = tr[p][ch - 'a'];
    for (int j = p; j; j = fail[j]) {
      val[j]++;
    }
  }
  int mx = 0;
  for (int i = 0; i <= tot; i++) {
    if (idx[i]) {
      mx = std::max(mx, val[i]);
      cnt[idx[i]] = val[i];
    }
  }
  return mx;
}

void solve(int n) {
  init();
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    insert(a[i], i);
  }
  build();
  std::string str;
  std::cin >> str;
  int mx = query(str);
  std::cout << mx << '\n';
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == mx) {
      std::cout << a[i] << '\n';
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;

  while (std::cin >> n && n) {
    solve(n);
  }

  return 0;
}