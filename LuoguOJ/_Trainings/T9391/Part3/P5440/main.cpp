// 优化了好多次终于AC
// 开O2反而慢了0.8s

#include <bits/stdc++.h>
using namespace std;

int pri[20000000], pricnt = 0;
bitset<100000000> vis;

bool checkExist(int n) {
  int m = n / 100 % 100, y = n / 10000, d = n % 100;
  if (m > 12 || d > 31 || m == 0 || d == 0 || y == 0) return false;
  if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
  if (m == 2) {
    if (y % 3200 == 0) return d <= 28;
    if ((y % 4 == 0 && y % 100) || y % 400 == 0) return d <= 29;
    return d <= 28;
  }
  return true;
}

inline int pow10(int n) {
  int t = 1;
  while (n--) {
    t = (t << 1) + (t << 3);
  }
  return t;
}

bool check(int num[]) {
  int n = 0;
  for (int i = 7; i >= 0; i--) {
    n += num[i] * pow10(7 - i);
    if ((i == 6 || i == 4 || i == 0) && vis[n]) return false;
  }
  return checkExist(n);
}

int ans = 0;

void dfs(const vector<int> &sp, int cur, int nums[]) {
  for (int i = 0; i < 10; i++) {
    nums[sp[cur]] = i;
    if (cur != sp.size() - 1) dfs(sp, cur + 1, nums);
    else {
      if (check(nums)) {
        ans++;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  string str;

  vis[1] = vis[0] = true;
  for (int i = 2; i <= 99999999; i++) {
    if (!vis[i]) {
      pri[pricnt++] = i;
    }
    for (int j = 0; j < pricnt; j++) {
      int p = pri[j];
      if (1ll * i * p > 99999999) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  while (T--) {
    cin >> str;
    if (str == "--------") {
      cout << 55157 << '\n';
      continue;
    }
    int nums[8];
    vector<int> sp;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '-') {
        nums[i] = -1;
        sp.push_back(i);
      } else nums[i] = str[i] - '0';
    }
    int cur = 0;
    ans = 0;
    if (!sp.empty())
      dfs(sp, cur, nums);
    else ans = check(nums);
    cout << ans << '\n';
  }
  return 0;
}