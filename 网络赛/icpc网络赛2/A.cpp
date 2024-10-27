#include <bits/stdc++.h>
#define int long long

struct Team {
  int w;
  std::string name;
  int idx;
  bool operator < (const Team &b) const {
    return w > b.w;
  }
};

signed main() {
  freopen("A.in", "r", stdin);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> c(k + 1), ans(n + 1);
  int minc = INT_MAX;
  for (int i = 1; i <= k; i++) {
    std::cin >> c[i];
    minc = std::min(minc, c[i]);
  }
  std::vector<Team> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].w >> a[i].name;
    a[i].idx = i;
  }
  std::sort(a.begin() + 1, a.end());
  std::map<std::string, int> cnt;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    auto &[w, name, idx] = a[i];
    cnt[name]++;
    sum++;
    if (cnt[name] > minc) {
      cnt[name] = minc;
      sum--;
    }
    ans[idx] = sum;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i]<< '\n';
  }
  return 0;
}