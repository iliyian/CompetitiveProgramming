// date: 2024-08-17 11:28:53
// tag: AC自动机模板

#include <bits/stdc++.h>
// using namespace std;

constexpr int N = 1e6;

std::vector<std::array<int, 26>> tr(N + 1);
std::vector<int> e(N + 1), fail(N + 1);
int tot = 0;

void insert(std::string &str) {
  int u = 0;
  for (char ch : str) {
    if (!tr[u][ch - 'a']) tr[u][ch - 'a'] = ++tot;
    u = tr[u][ch - 'a'];
  }
  e[u]++;
}

void build() {
  std::queue<int> q;
  for (int i = 0; i < 26; i++) {
    if (tr[0][i]) {
      q.push(tr[0][i]);
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < 26; i++) { // u与其说是cur，不如说是parent
      if (tr[u][i]) {
        fail[tr[u][i]] = tr[fail[u]][i];
        q.push(tr[u][i]);
      } else {
        tr[u][i] = tr[fail[u]][i];
      }
    }
  }
}

int query(std::string &str) {
  int u = 0, ans = 0;
  for (char ch : str) {
    u = tr[u][ch - 'a'];
    for (int j = u; j != 0 && e[j] != -1; j = fail[j]) {
      ans += e[j], e[j] = -1;
    }
  }
  return ans;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  std::cin >> n;
  std::string str;
  for (int i = 1; i <= n; i++) {
    std::cin >> str;
    insert(str);
  }
  build();
  std::cin >> str;
  std::cout << query(str) << '\n';

  return 0;
}