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

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);

  int n, ans = 0;
  cin >> n;
  vector<string> strs;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    strs.push_back(str);
    for (int j = 1; j <= str.size(); j++) {
      sum[i][j] = str[j - 1] - '0' + sum[i][j - 1];
    }
    f[str.size()][sum[i][str.size()]]++;
  }

  for (int i = 0; i < n; i++) {
    string &str = strs[i];
    for (int j = 0; j <= str.size(); j++) {
      int lenl = j, lenr = str.size() - j;
      int len = abs(lenl - lenr);
      int suml = sum[i][lenl], sumr = sum[i][str.size()] - sum[i][lenl];
      ans += f[len][abs(suml - sumr)];
    }
  }

  return 0;
}