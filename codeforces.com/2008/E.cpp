#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  std::vector<std::array<std::vector<int>, 2>> cnt(26);
  str = '#' + str;
  for (int i = 1; i <= n; i++) {
    cnt[str[i] - 'a'][i & 1].push_back(i);
  }
  for (int i = 0; i < 26; i++) {
    for (auto &x : cnt[i][0]) {

    }
  }
  std::vector<std::array<std::array<int, 2>, 26>> b(n + 2), c(n + 2);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      b[i][j][i & 1] = b[i - 1][j][i & 1] + (str[i] == j + 'a');
      b[i][j][i & 1 ^ 1] = b[i - 1][j][i & 1 ^ 1];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < 26; j++) {
      c[i][j][i & 1] = c[i + 1][j][i & 1] + (str[i] == j + 'a');
      c[i][j][i & 1 ^ 1] = c[i + 1][j][i & 1 ^ 1];
    }
  }
  int ans = INT_MAX;
  auto countr = [&](int ch, int t, int x) {
    // auto &v = cnt[ch][t];
    // assert(c[x + 1][ch][t] == v.end() - std::upper_bound(v.begin(), v.end(), x));
    return c[x + 1][ch][t];
    // return v.end() - std::upper_bound(v.begin(), v.end(), x);
  };
  auto countl = [&](int ch, int t, int x) {
    // auto &v = cnt[ch][t];
    // assert(b[x][ch][t] == v.size() - countr(ch, t, x));
    return b[x][ch][t];
    // return v.size() - countr(v, x);
  };
  if (n & 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 26; j++) {
        for (int k = j; k < 26; k++) {
          // if (j == k)
          //   continue;
          // j 奇, k 偶
          ans = std::min({
              ans,
              // [0,i - 1]的j且i&1^1的个数
              (int)(n - 1 - countl(j, 0, i - 1) - countr(j, 1, i) -
                  countl(k, 1, i - 1) - countr(k, 0, i)),
              (int)(n - 1 - countl(j, 1, i - 1) - countr(j, 0, i) -
                  countl(k, 0, i - 1) - countr(k, 1, i)),
          });
        }
      }
    }
  } else {
    for (int i = 0; i < 26; i++) {
      for (int j = i; j < 26; j++) {
        // if (i == j)
        //   continue;
        ans = std::min(
            {ans, (int)(n - cnt[i][0].size() - cnt[j][1].size()),
            (int)(n - cnt[i][1].size() - cnt[j][0].size())});
      }
    }
  }
  ans = std::max(ans, 0ll);
  std::cout << ans + (n & 1) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}