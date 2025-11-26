#include <bits/stdc++.h>
#define int long long

std::map<int, int> sg;

std::mt19937_64 rd(std::random_device{}());

using u64 = unsigned long long;

std::vector<int> a87(87), a34(34);

int get(int x) {
  if (x <= 86) return a87[x];
  return a34[x % 34];
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::map<int, u64> mp;
  std::set<u64> s;
  std::vector<int> p;
  std::vector<std::array<int, 2>> a;
  for (int i = 1; i <= m; i++) {
    int l, r;
    std::cin >> l >> r;
    a.push_back({l, r});
  }
  mp[0] = 0;
  for (auto [l, r] : a) {
    p.push_back(l);
    p.push_back(r);
    u64 x = rd();
    s.insert(x);
    if (l > r) {
      std::swap(l, r);
    }
    mp[l + 1] ^= x;
    mp[r] ^= x;
  }
  std::sort(p.begin(), p.end());
  std::map<u64, int> cnt;
  int prv = 0;
  u64 prx = 0;
  for (auto &[k, v] : mp) {
    v ^= prx;
    int len = k - prv;
    cnt[prx] += len;
    prv = k;
    prx = v;
  }
  cnt[prx] += n - prv;
  for (int i : p) {
    auto l = --mp.upper_bound(i);
    cnt[l->second]--;
  }
  int _tot = 0, ans = 0;
  for (auto &[k, v] : cnt) {
    _tot += v;
    ans ^= get(v);
  }
  std::cout << (ans ? "YES" : "NO") << '\n';
}

int work(int x) {
  if (x <= 1) return 0;
  if (sg.count(x)) {
    return sg[x];
  }
  std::set<int> s;
  for (int i = 0; x - 2 - i >= i; i++) {
    int a = work(i), b = work(x - 2 - i);
    s.insert(a ^ b);
  }
  int mex = 0;
  while (s.count(mex)) mex++;
  return sg[x] = mex;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n = 1000, prv = 0;
  for (int i = 0; i <= 200; i++) {
    if (i <= 86) {
      a87[i] = work(i);
    } else {
      a34[i % 34] = work(i);
    }
  }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}