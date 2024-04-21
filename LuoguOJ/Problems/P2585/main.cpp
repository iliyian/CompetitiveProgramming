#include <bits/stdc++.h>
#define N 500001
using namespace std;

string str;

int cnt = 0;

int fi[N][3], fx[N][3];


void dfs(int n) {
  if (str[n] == '0') {
    fi[n][0] = fx[n][0] = 1;
    return;
  }
  int l = ++cnt;
  dfs(l);

  if (str[n] == '1') {
    fi[n][0] = min(fi[l][1], fi[l][2]) + 1;
    fi[n][1] = min(fi[l][0], fi[l][2]);
    fi[n][2] = min(fi[l][1], fi[l][0]);

    fx[n][0] = max(fx[l][1], fx[l][2]) + 1;
    fx[n][1] = max(fx[l][0], fx[l][2]);
    fx[n][2] = max(fx[l][1], fx[l][0]);
  }
  if (str[n] == '2') {
    int r = ++cnt;
    dfs(r);

    fi[n][0] = min(fi[l][1] + fi[r][2], fi[l][2] + fi[r][1]) + 1;
    fi[n][1] = min(fi[l][0] + fi[r][2], fi[l][2] + fi[r][0]);
    fi[n][2] = min(fi[l][1] + fi[r][0], fi[l][0] + fi[r][1]);

    fx[n][0] = max(fx[l][1] + fx[r][2], fx[l][2] + fx[r][1]) + 1;
    fx[n][1] = max(fx[l][0] + fx[r][2], fx[l][2] + fx[r][0]);
    fx[n][2] = max(fx[l][1] + fx[r][0], fx[l][0] + fx[r][1]);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> str;
  str = '#' + str;
  dfs(++cnt);
  cout << max(fx[1][0], max(fx[1][1], fx[1][2])) << ' ' << min(fi[1][0], min(fi[1][1], fi[1][2]));
  return 0;
}