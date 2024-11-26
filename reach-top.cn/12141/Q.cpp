#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

std::vector<int> pri, vis(N + 1);

bool ispa(std::string str) {
  std::string rev = str;
  std::reverse(rev.begin(), rev.end());
  return rev == str;
}

int check(std::string a, std::string b) {
  int ans = 0;
  for (int i = 0; i + b.size() <= a.size(); i++) {
    if (a.substr(i, b.size()) == b) {
      ans++;
    }
  }
  return ans;
}

void solve() {
  std::string str;
  std::getline(std::cin, str);
  int ans = 4;
  bool a = 0, b = 0, c = 0, d = 0;
  for (int i = 0; i < str.size(); i++) {
    if (isupper(str[i])) a = 1;
    if (islower(str[i])) b = 1;
    if (isdigit(str[i])) c = 1;
    if (!isalnum(str[i])) d = 1;
  }
  std::cout << "level-" << (ans - !a - !b - !c - !d) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}