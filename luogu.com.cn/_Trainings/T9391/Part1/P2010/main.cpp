// 说起来我总是忘记写输入输出

#include <bits/stdc++.h>
using namespace std;

struct Day {
  int y, m, d;
};

bool isRun(int n) {
  return ((!(n % 4) && n % 100) || !(n % 400));
}

int lim[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void step(int &date) {
  int y = date / 10000, m = date / 100 % 100, d = date % 100;
  if (d <= 27) {
    d++;
  }
  else if (d == 31 && m == 12) {
    d = 1, m = 1, y++;
  }
  else if (m == 2) {
    if (isRun(y) && d == 28) {
      d++;
    } else {
      m = 3;
      d = 1;
    }
  } else {
    if (d == lim[m]) {
      d = 1, m++;
    } else {
      d++;
    }
  }
  date = y * 10000 + m * 100 + d;
}

bool isPalin(const int &num) {
  string str = to_string(num);
  for (int i = 0; i <= str.size() / 2; i++)
    if (str[i] != str[str.size() - 1 - i])
      return false;
  return true;
}

int main() {
  // freopen("data.out", "w", stdout);
  int l, r, ans = 0;
  cin >> l >> r;
  while (l <= r) {
    ans += isPalin(l);
    // cout << "l=" << l << ",isPalin= " << (isPalin(l) ? "True" : "False") << endl;
    step(l);
  }
  cout << ans;
  return 0;
}