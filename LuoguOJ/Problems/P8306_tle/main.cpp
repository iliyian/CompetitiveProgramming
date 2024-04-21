#include <bits/stdc++.h>
#define N 3000000
using namespace std;

int nxt[N][62], cnt[N];
int id = 0;

inline int idx(char c) {
  if ('0' <= c && c <= '9') {
    return c - '0' + 52;
  } else if ('a' <= c && c <= 'z') {
    return c - 'a';
  }
  return c - 'A' + 26;
}

void insert(const string &str) {
  int p = 0;
  int len = str.size();
  for (int i = 0; i < len; i++) {
    int d = idx(str[i]);
    if (!nxt[p][d]) nxt[p][d] = ++id;
    cnt[p = nxt[p][d]]++; // steps up up
  }
}

int find(const string &str) {
  int p = 0;
  int len = str.size();
  for (int i = 0; i < len; i++) {
    p = nxt[p][idx(str[i])];
    if (p == 0) return 0;
  }
  return cnt[p];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 62; j++) {
        nxt[i][j] = 0;
      }
    }
    for (int i = 0; i < N; i++) {
      cnt[i] = 0;
    }
    int n, q;
    cin >> n >> q;
    string str;
    for (int i = 0; i < n; i++) {
      cin >> str;
      insert(str);
    }
    int ans = 0;
    for (int i = 0; i < q; i++) {
      cin >> str;
      cout << find(str) << '\n';
    }
  }
  return 0;
}