#include <bits/stdc++.h>
using namespace std;

int L[200001], sum[5][200001], sorted[5][200001];
int f[6][200001];

int getlen(int x) {
  int len = 0;
  if (x == 0) return 0;
  while (x) {
    x /= 10, len++;
  }
  return len;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);

  int n;
  cin >> n;
  memset(sorted, 0x3f, sizeof(sorted));
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 1; j <= str.size(); j++) {
      sum[j][i] = str[j - 1] - '0' + sum[j - 1][i];
      sorted[j][i] = sum[j][i];
      sum[j][sum[j][i]]++;
    }
    L[i] = str.size();
  }
  int ans = 0;
  for (int i = 0; i < 5; i++)
    sort(sorted[i], sorted[i] + 200001);

  for (int i = 0; i < n; i++) {
    for (int len = 1; len <= L[i]; len++) {
      for (int l = 1; l <= L[i] - len; l++) {
        int r = l + len;
        int v2 = sum[r][i] - sum[l - 1][i], v1 = sum[l][i];
        int v = v2 - v1;
        int x = lower_bound(sorted[len], sorted[len] + 200001, v) - sorted[len];
        ans += count(sorted[len], sorted[len] + 200001, v);
      }
    }
  }

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     if (j == i) {ans++; continue;}
  //     if ((L[i] + L[j]) & 1) continue;
  //     int len = (L[i] + L[j]) >> 1;
  //     if (len > L[i]) {
  //       int l = sum[i][L[i] - 1] + (sum[j][len - 1 - L[i]]);
  //       int r = sum[j][L[j] - 1] - sum[j][L[j] - 1 - len];
  //       ans += l == r;
  //     } else {
  //       int r = sum[j][L[j] - 1] + (sum[i][L[i] - 1] - sum[i][L[i] - 1 - (len - L[j])]);
  //       int l = sum[i][L[i] - 1 - (len - L[j])];
  //       ans += l == r;
  //     }
  //   }
  // }
  cout << ans;
  return 0;
}