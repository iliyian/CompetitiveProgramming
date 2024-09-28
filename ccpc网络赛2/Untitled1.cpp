#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[(int)1e6 + 10], b[(int)1e6 + 10], sum1, sum2, T, t1, t2, pos;
signed main() {
  scanf("%lld", &T);

  while (T) {
    T--;
    scanf("%lld", &n);

    for (int i = 1; i <= n; i++)
      scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++)
      scanf("%lld", &b[i]);

    sum1 = sum2 = 0;
    for (int i = 1; i <= n; i++) {
      sum1 ^= a[i];
      sum2 ^= b[i];
    }
    // cout <<"sum:"<<sum1 <<' ' <<sum2<<endl;
    for (int k = 31; k > 0; k--) {
      t1 = sum1;
      t2 = sum2;
      pos = 0;
      if ((sum1 & (1 << k - 1)) && (sum2 & (1 << k - 1))) {
        for (int i = 1; i <= n; i++)
          if ((a[i] ^ b[i]) <= (1 << k) - 1 &&
              ((a[i] & (1 << k - 1)) != (b[i] & (1 << k - 1)))) {
            // cout << (sum1 ^ (1 << k - 1)) << (sum1 ^ (1 << k - 1))<<endl;
            // cout <<k << ' '<<a[i] << ' ' <<b[i]<<' '<< sum1 << ' '<<sum2 <<
            // endl;
            if (max(sum1 ^ a[i] ^ b[i], sum2 ^ a[i] ^ b[i]) < max(t1, t2)) {
              t1 = sum1 ^ a[i] ^ b[i];
              t2 = sum2 ^ a[i] ^ b[i];
              pos = i;
            }
          }
      } else if (((sum1 & (1 << k - 1)) == 1 && (sum2 & (1 << k - 1)) == 0 &&
                  sum1 > sum2) ||
                 ((sum1 & (1 << k - 1)) == 0 && (sum2 & (1 << k - 1)) == 1 &&
                  sum1 < sum2)) {
        for (int i = 1; i <= n; i++)
          if ((a[i] ^ b[i]) <= (1 << k) - 1 &&
              ((a[i] & (1 << k - 1)) != (b[i] & (1 << k - 1)))) {
            // cout<<"*" <<k << ' '<<a[i] << ' ' <<b[i]<<' '<<sum1 << '
            // '<<sum2<<endl;
            if (max(sum1 ^ a[i] ^ b[i], sum2 ^ a[i] ^ b[i]) < max(t1, t2)) {
              t1 = sum1 ^ a[i] ^ b[i];
              t2 = sum2 ^ a[i] ^ b[i];
              pos = i;
            }
          }
      }
      swap(a[pos], b[pos]);
      sum1 = t1;
      sum2 = t2;
    }
    printf("%lld\n", max(sum1, sum2));
  }
}
