#include <bits/stdc++.h>
#define int long long
// using namespace std;

int ask(int l, int r, int k) {
  std::cout << "? " << l << ' ' << r << ' ' << k << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void answer(int x) {
  std::cout << "! " << x << std::endl;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> q(n + 2, std::vector<int>(n + 2));
  if (n % 2) {
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      int cl = 2 * ask(1, mid, 2) - mid;
      int cr = 2 * ask(mid + 1, n, 2) - (n - mid);
      if (cl < cr) l = mid + 1;
      else r = mid;
      // std::cout << "~ " << l << ' ' << r << '\n';
    }
    answer(l);
    return 0;
  }

  int l = 1, r = n, npos = 0;
  while (l < r) {
    int mid = (l + r) / 2;
    if (l == mid) {
      if (npos) {
        if (q[1][l - 1] + 1 == q[1][r]) {
          int c = ask(1, l, 2);
          if (c == q[1][l - 1]) l = r;
        } else if (q[1][r + 1] + 1 == q[l][n]) {
          int c = ask(r, n, 2);
          if (c != q[r + 1][n]) l = r;
        }
      } else {
        int c = 0;
        if (mid == 1) {
          c = 3 - ask(2, n, n);
        } else {
          c = ask(1, mid, n);
        }
        if (c == 2) l = r;
      }
      break;
    }
    int cl = 2 * ask(1, mid, 2) - mid - (npos == 1);
    int cr = 2 * ask(mid + 1, n, 2) - (n - mid) - (npos == n);
    q[1][mid] = cl, q[mid + 1][n] = cr;
    if (cl < cr) l = mid + 1;
    else if (cl > cr) r = mid;
    else {
      int c = 0;
      if (mid == 1) {
        c = 3 - ask(2, n, n);
      } else {
        c = ask(1, mid, n);
      }
      if (c == 2) npos = 1, l = mid + 1;
      else npos = n, r = mid;
    }
  }
  answer(l);

  return 0;
}