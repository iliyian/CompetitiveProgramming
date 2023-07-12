// 切记交卷前删掉freopen
// 大数据不易错，小数据易错

#include <bits/stdc++.h>
using namespace std;

int n;
string words[20];

// beast
// stonish

int getSameLen(const string &a, const string &b) {
  // cout << "a=" << a << ",b=" << b << endl;
  int mlen = min(a.size(), b.size());
  // int len = 1e9;
  for (int i = 1; i < mlen; i++) {
    string ta = a.substr(a.size()-i, i);
    string tb = b.substr(0, i);
    // cout << "i=" << i << ",ta=" << ta << ",tb=" << tb << endl;
    if (ta == tb) return i;;
  }
  return 0;
}

int vis[20], ans = -1;

void dfs(string &dragon) {
  // cout << "dragon=" << dragon << endl;
  ans = max(ans, int(dragon.size()));
  for (int i = 0; i < n; i++) {
    if (vis[i] >= 2) continue;
    int res = getSameLen(dragon, words[i]);
    int wsize = words[i].size();

    // cout << "i=" << i << ",res=" << res << endl;
    if(res == 0 || res == min(int(dragon.size()), wsize)) continue;

    vis[i]++;
    dragon += words[i].substr(res, wsize - res);
    dfs(dragon);
    dragon.erase(dragon.size() - (wsize - res), wsize - res);
    vis[i]--;
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(vis, 0, sizeof(vis));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> words[i];
  }

  char head;
  cin >> head;

  for (int i = 0; i < n; i++) {
    if (words[i][0] == head) {
      string dragon = words[i];
      vis[i]++;
      dfs(dragon);
      vis[i]--;
    }
  }

  cout << ans << endl;
  return 0;
}