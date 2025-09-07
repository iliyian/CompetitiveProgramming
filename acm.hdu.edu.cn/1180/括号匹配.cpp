#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  std::vector<int> d1(n), d2(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : std::min(d1[l + r - 1], r - i + 1);
    while (0 <= i - k && i + k < n && str[i - k] == str[i + k]) {
      k++;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : std::min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && str[i - k - 1] == str[i + k]) {
      k++;
    }
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k;
    }
  }
  std::vector<int> s(n);
  std::vector<int> L(n + 2, n + 1), R(n + 2, -1);
  for (int i = 0; i < n; i++) {
    s[i] = (i ? s[i - 1] : 0) + (str[i] == '(' ? 1 : str[i] == ')' ? -1 : 0);
    if (str[i] == ')') {
      for (int j = i - 1; j >= 0; j--) {
        if (std::isalpha(str[j])) break;
        if (str[j] == '(' && (j == 0 ? 0 : s[j - 1]) == s[i]) {
          R[i] = j, L[j] = i;
          break;
        }
      }
    }
  }
  // for (int i = 0; i < n; i++) {
  //   std::cout << R[i] << ' ' << i << '\n';
  // }
  // std::cout << '\n';
  // for (int i = 0; i < n; i++) {
  //   std::cout << i << ' ' << L[i] << '\n';
  // }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    // if (std::isalpha(str[i])) continue;
    for (int j = 1; j <= d1[i]; j++) {
      int l = i - j + 1, r = i + j - 1;
      if (l < 0 || r >= n) break;
      if (R[r] >= l || L[l] <= r) {
        // ans++;
        ans += d1[i] - j + 1;
        // std::cerr << i << ' ' << l << ' ' << r << '\n';
        break;
      }
    }
  }
  // std::cerr << '\n';
  for (int i = 0; i < n; i++) {
    // if (std::isalpha(str[i])) continue;
    for (int j = 1; j <= d2[i]; j++) {
      int l = i - j, r = i + j - 1;
      if (l < 0 || r >= n) break;
      if (R[r] >= l || L[l] <= r) {
        // ans++;

        // std::cerr << i << ' ' << l << ' ' << r << '\n';
        ans += d2[i] - j + 1;
        break;
      }
    }
  }
  std::cout << ans << '\n';
  // for (int i = 0; i < n; i++) {
  //   std::cout << d1[i] << " ";
  // }
  // std::cout << '\n';
  // for (int i = 0; i < n; i++) {
  //   std::cout << d2[i] << " ";
  // }
  // std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}