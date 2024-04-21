// wa#0 务必搞懂lenl,lenr等变量的使用，不要用混了

#include <bits/stdc++.h>
#define N 200001
#define int long long
using namespace std;

int sum[N][7];
int f[7][10000];

int getlen(int x) {
  int len = 0;
  if (x == 0) return 0;
  while (x) {
    x /= 10, len++;
  }
  return len;
}

int getsum(const string &str, int l, int r) {
  int ans = 0;
  for (int i = l; i <= r; i++)
    ans += str[i] - '0';
  return ans;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n, ans = 0;
  cin >> n;
  vector<vector<int>> s(n);
  vector<string> strs(n);
  map<pair<int, int>, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> strs[i];
    s[i].resize(strs.size() + 1);
    strs[i] = '0' + strs[i];
    for (int j = 1; j <= strs[i].size(); j++)
      s[i][j] = s[i][j - 1] + strs[i][j] - '0';
    cnt[make_pair(strs[i].size(), s[i][strs.size()])]++;
  }
  for (int L = 0; L < n; L++) {
    for (int lenr = strs[L].size() % 2; lenr <= strs[L].size(); lenr++) {
      int l = strs[L].size() + lenr;
      int suml = s[L][l / 2], sumr = s[L][strs[L].size()] - s[L][l / 2];
      if (suml > sumr)
        ans += cnt[lenr][suml - sumr];
    }
  }
  for (int L = 0; L < n; L++) {
    for (int lenr = strs[R].size() % 2; lenr < strs[L].size(); lenr++) {
      int l = strs[L].size() + lenr;
      int suml = s[L][l / 2], sumr = s[L][strs[L].size()] - s[L][l / 2];
      if (suml > sumr)
        ans += cnt[lenr][suml - sumr];
    }
  }

  cout << ans;

  return 0;
}