#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  int c1 = 0, c0 = 0;
  std::vector<int> lcy(n + 1), rcy(n + 2), lcs(n + 2), rcs(n + 2), 
    lce(n + 1), rce(n + 2), lcn(n + 1), rco(n + 2), rcn(n + 1), lco(n + 1);
  for (int i = 1; i <= n; i++) {
    lcy[i] = lcy[i - 1];
    lce[i] = lce[i - 1];
    lcs[i] = lcs[i - 1];
    lcn[i] = lcn[i - 1];
    lco[i] = lco[i - 1];
    if (str[i] == 'N') lcn[i]++;
    if (str[i] == 'O') c0 += lcn[i], lco[i]++;
    if (str[i] == 'Y') lcy[i]++;
    if (str[i] == 'E') lce[i] += lcy[i];
    if (str[i] == 'S') c1 += lce[i], lcs[i]++;
  }
  // std::cerr << c1 << ' ' << c0 << '\n';
  c1 = 0, c0 = 0;
  for (int i = n; i >= 1; i--) {
    rcs[i] = rcs[i + 1];
    rce[i] = rce[i + 1];
    rcy[i] = rcy[i + 1];
    rco[i] = rco[i + 1];
    rcn[i] = rcn[i + 1];
    if (str[i] == 'O') rco[i]++;
    if (str[i] == 'N') c0 += rco[i], rcn[i]++;
    if (str[i] == 'S') rcs[i]++;
    if (str[i] == 'E') rce[i] += rcs[i];
    if (str[i] == 'Y') c1 += rce[i], rcy[i]++;
  }
  std::cout << c1 << ' ' << c0 << '\n';
  if (c0 == c1) {
    std::cout << "DUI DUI DUIMA\n";
    return;
  }

  auto to = [&](int i, char s, char t) {
    auto ans = std::pair{c1, c0};
    auto _lcy = lcy[i], _rcy = rcy[i];
    auto _lce = lce[i], _rce = rce[i];
    auto _lcs = lcs[i], _rcs = rcs[i];
    auto _lcn = lcn[i], _rcn = rcn[i];
    auto _lco = lco[i], _rco = rco[i];
    if (s == 'Y') {
      ans.first -= _rce;
      _lcy--, _rcy--;
    }
    if (s == 'E') {
      ans.first -= _lcy * _rcs;
      _lce -= _lcy, _rce -= _rcs;
    }
    if (s == 'S') {
      ans.first -= _lce;
      _lcs--, _rcs--;
    }
    if (s == 'N') {
      ans.second -= _rco;
      _lcn--, _rcn--;
    }
    if (s == 'O') {
      ans.second -= _lcn;
      _lco--, _rco--;
    }

    if (t == 'Y') {
      ans.first += _rce;
    }
    if (t == 'E') {
      ans.first += _lcy * _rcs;
    }
    if (t == 'S') {
      ans.first += _lce;
      // if (i == 17) {
      //   std::cerr << _lce << '\n';
      // }
    }
    if (t == 'N') {
      ans.second += _rco;
    }
    if (t == 'O') {
      ans.second += _lcn;
    }
    return ans;
  };

  std::string yesno = "YESNO";
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 5; j++) {
      if (str[i] == yesno[j]) continue;
      auto ans = to(i, str[i], yesno[j]);
      // if (i == 17 && j == 2) {
      //   std::cerr << ans.first << ' ' << ans.second << '\n';
        // std::cerr << str[i] << ' ' << yesno[j] << '\n';
      // }
      if (c1 > c0 && ans.first < ans.second) {
        std::cout << "O BUDUI BUDUI\n";
        // std::cerr << i << ' ' << yesno[j] << '\n';
        // std::cerr << ans.first << ' ' << ans.second << '\n';
        return;
      }
      if (c1 < c0 && ans.first > ans.second) {
        std::cout << "O DUI DE\n";
        // std::cerr << i << ' ' << yesno[j] << '\n';
        // std::cerr << ans.first << ' ' << ans.second << '\n';
        return;
      }
    }
  }
  if (c1 > c0) {
    std::cout << "DUI DE\n";
  } else {
    std::cout << "BUDUI BUDUI\n";
  }
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