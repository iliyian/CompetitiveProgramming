#include <bits/stdc++.h>
using namespace std;

struct Price {
  int p, s;
} prices[2000];

bool operator < (const Price &a, const Price &b) {
  return a.p < b.p;
}

int main() {
  int expect, costs, rawsale, expectedsale;
  cin >> expect >> costs >> rawsale;
  int price, sale, cnt = 0;
  while (cin >> price >> sale) {
    if (price == expect) expectedsale = sale;
    if (price == -1) break;
    Price &P = prices[cnt++];
    P.p = price, P.s = sale; 
  }
  sort(prices, prices + cnt);
  int maxwin = -1;
  for (int i = 0; i < cnt - 1; i++) {
    int p1 = prices[i].p, s1 = prices[i].s;
    int p2 = prices[i + 1].p, s2 = prices[i + 1].s;
    double k = (double(s2 - s1) / (p2 - p1));
    for (int j = p1 + 1; j < p2; j++) {
      maxwin = max(double(maxwin), k * (j - p1) + s1);
    }
  }

}