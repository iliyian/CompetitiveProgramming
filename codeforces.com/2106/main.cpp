#define int long long

signed main() {
  for (int i = 2; i < 100; i++) {
    bool f = false;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        f = true;
        break;
      }
    }
    if (!f) {
    }
  }
  return 0;
}