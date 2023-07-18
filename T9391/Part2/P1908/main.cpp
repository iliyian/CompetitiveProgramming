// 我打心里讨厌数组下标从1开始的习惯，和由此衍生而来的翻飞的各种 +1-1

#include <bits/stdc++.h>
using namespace std;

int read() {
  int sum = 0; char ch = getchar();
  while (isdigit(ch)) {sum = sum * 10 + ch - '0'; ch = getchar();}
  return sum;
}

vector<int> v;
long long ans = 0;

void midsort(int l, int r) {
  int mid = (l + r) / 2;
  if (r - l <= 1) return ;
  midsort(l, mid);
  midsort(mid, r);
  vector<int> temp;
  int i = l, j = mid;
  while (i < mid && j < r) {
    if (v[i] <= v[j]) {
      temp.push_back(v[i++]);
    } else {
      ans += mid - i;
      temp.push_back(v[j++]);
    }
  }
  while (i < mid) temp.push_back(v[i++]);
  while (j < r) temp.push_back(v[j++]);
  int k = 0;
  for (int i = l; i < r; i++) v[i] = temp[k++];
}

void print(long long n) {
  if (n > 9) print(n / 10);
  putchar(n % 10 + '0');
}

int main() {
  // freopen("data.in", "r", stdin);
  int n = read();
  for (int i = 0; i < n; i++) {
    int a = read();
    v.push_back(a);
  }
  midsort(0, v.size());
  print(ans);
  return 0;
}