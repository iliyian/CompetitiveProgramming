// date: 2025-08-14 01:27:15
// tag:
// 应该是3个小错误，一个是leapcnt的差分形式转换失败，这和daycnt的后缀和形式是不同的，
// 另一个是前缀算的是年份最后一个数字是当前数字的，这里没写对，还有0也是

#include <bits/stdc++.h>
#define int long long

int month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
std::map<std::string, int> mp, mp2;
std::vector<std::vector<int>> adj(1000, std::vector<int>(10));
std::vector<std::vector<int>> adj2(7000, std::vector<int>(10));
std::vector<std::vector<int>> has(10), has2(10);
std::vector<int> days, leaps, isleap(7000);
int tot = 0, very = 0, tot2 = 0;

constexpr int mod = 998244353;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

const int inv24 = qpow(24, mod - 2);
const int inv6 = qpow(6, mod - 2);

int C4(int n) {
  if (n < 4) return 0;
  return n * (n - 1) % mod * (n - 2) % mod * (n - 3) % mod * inv24 % mod;
}

int C3(int n) {
  if (n < 3) return 0;
  return n * (n - 1) % mod * (n - 2) % mod * inv6 % mod;
}

void solve() {
  int n;
  std::cin >> n;
  std::string str; 
  std::cin >> str;
  // int n = str.size();
  str = '#' + str;
  std::vector<int> cnt(1000), cnt2(7000);
  std::vector<int> daycnt(n + 2), verycnt(n + 2);
  for (int i = n; i >= 1; i--) {
    std::string s(1, str[i]);
    auto ncnt = cnt;
    ncnt[mp[s]]++;
    ncnt[mp[s]] %= mod;
    for (int j : has[str[i] - '0']) {
      ncnt[adj[j][str[i] - '0']] += cnt[j];
      ncnt[adj[j][str[i] - '0']] %= mod;
    }
    cnt = std::move(ncnt);
    verycnt[i] = cnt[very];
    for (auto j : days) {
      daycnt[i] += cnt[j];
      daycnt[i] %= mod;
    }
  }
  
  std::vector<int> leapcnt(n + 1);
  for (int i = 1; i <= n; i++) {
    std::string s(1, str[i]);
    auto ncnt2 = cnt2;
    ncnt2[mp2[s]]++;
    ncnt2[mp2[s]] %= mod;
    for (int j : has2[str[i] - '0']) {
      auto v = adj2[j][str[i] - '0'];
      ncnt2[v] += cnt2[j];
      ncnt2[v] %= mod;
      if (isleap[v]) {
        leapcnt[i] += cnt2[j];
        leapcnt[i] %= mod;
      }
    }
    cnt2 = std::move(ncnt2);
  }
  int ans = 0, cnt0 = 0;
  for (int i = 1; i <= n - 1; i++) {
    cnt0 += str[i] == '0';
    int normalday = (daycnt[i + 1] - verycnt[i + 1] + mod) % mod;
    int cur = (C3(i - 1) - (str[i] == '0' ? C3(cnt0 - 1) : 0) + mod) % mod * normalday % mod;
    cur += leapcnt[i] * verycnt[i + 1] % mod;
    ans += cur;
    ans %= mod;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);


  int cnt = 0;
  for (int i = 1; i <= 9999; i++) {
    if (i % 4 == 0 && (i % 100 || i % 400 == 0)) {
      std::string s;
      if (i < 10) s = '0' + s;
      if (i < 100) s = '0' + s;
      if (i < 1000) s = '0' + s;
      s += std::to_string(i);
      mp2[s] = ++tot2;
      leaps.push_back(tot2);
      // std::cerr << s << '\n';
      isleap[tot2] = 1;
      
      std::string t;
      for (int j = 0; j <= 2; j++) {
        t = t + s[j];
        if (!mp2.count(t)) {
          mp2[t] = ++tot2;
        }
      }
      for (int j = 1; j <= 3; j++) {
        // std::cerr << s.substr(0, i) << ' ' << s[i] - '0' << ' ' << s.substr(0, i + 1) << '\n';
        adj2[mp2[s.substr(0, j)]][s[j] - '0'] = mp2[s.substr(0, j + 1)];
      }
    }
  }

  for (int m = 1; m <= 12; m++) {
    for (int d = 1; d <= month[m]; d++) {
      std::string s;
      if (m < 10) s += '0';
      s += std::to_string(m);
      if (d < 10) s += '0';
      s += std::to_string(d);
      mp[s] = ++tot;

      days.push_back(tot);
      if (m == 2 && d == 29) {
        very = tot;
      }
      std::string t;
      for (int i = 3; i >= 1; i--) {
        t = s[i] + t;
        // std::cerr << m << ' ' << d << ' ' << s << ' ' << t << '\n';
        if (!mp.count(t)) { 
          mp[t] = ++tot;
        }
      }
      for (int i = 3; i >= 1; i--) {
        adj[mp[s.substr(i, 4 - i)]][s[i - 1] - '0'] = mp[s.substr(i - 1, 5 - i)];
      }
      // std::cerr << m << ' ' << d << ' ' << s << '\n';
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 1; j <= tot; j++) {
      if (adj[j][i]) {
        has[i].push_back(j);
      }
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 1; j <= tot2; j++) {
      if (adj2[j][i]) {
        has2[i].push_back(j);
      }
    }
  }


  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}