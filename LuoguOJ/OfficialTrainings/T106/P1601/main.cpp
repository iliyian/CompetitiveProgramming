#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;

struct Big {

};

int main() {
  int a[502], b[502], c[502];
  char s[502];
  scanf("%s", s);
  int alen = 0, blen = 0, clen = 0;
  for (int i = strlen(s) - 1; i >= 0; i--) {
    a[alen++] = s[i] - '0';
  }
  scanf("%s", s);
  for (int i = strlen(s) - 1; i >= 0; i--) b[blen++] = s[i] - '0';
  int carry = 0;
  for (int i = 0; i < max(alen, blen); i++) {
    if (i < alen) carry += a[i];
    if (i < blen) carry += b[i];
    // printf("carry=%d\n", carry);
    c[clen++] = carry % 10;
    carry /= 10;
  }
  if (carry) printf("%d", carry);
  for (int i = clen - 1; i >= 0; i--) {
    printf("%d", c[i]);
  }
  return 0;
}