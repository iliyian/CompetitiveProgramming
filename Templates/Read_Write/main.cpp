#include <bits/stdc++.h>
using namespace std;

const int N = 100000000;

vector<int> pri;
bitset<N + 1> vis;

void genPrime() {
  pri.push_back(2);
  for (int i = 3; i <= N; i += 2) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int j = 0; j < pri.size(); j++) {
      long long t = 1ll * i * pri[j];
      if (t > N) break;
      vis[t] = true;
      if (i % pri[j] == 0) break;
    }
  }
}

double echoTime(const chrono::steady_clock::time_point &begin, const chrono::steady_clock::time_point &end) {
  auto dur = chrono::duration_cast<chrono::microseconds>(end - begin);
  return double(dur.count()) * chrono::microseconds::period::num / chrono::microseconds::period::den;
}

void testIostream() {
  auto begin = chrono::steady_clock::now();
  for (int i = 0; i < pri.size(); i++) {
    cout << pri[i] << ' ';
  }
  int x;
  while (cin >> x) {
    x <<= 1;
  }
  auto end = chrono::steady_clock::now();
  cout << "\nTest iostream " << echoTime(begin, end) << " seconds.\n";
}

void testStdio() {
  auto begin = chrono::steady_clock::now();
  for (int i = 0; i < pri.size(); i++)
    printf("%d ", pri[i]);
  int x;
  while (scanf("%d", &x) == 1) {
    x <<= 1;
  }
  auto end = chrono::steady_clock::now();
  printf("\nTest stdio %lf seconds.\n", echoTime(begin, end));
}

void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  int sta[35], top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top--) putchar(sta[top] + '0');
}

void read(int &x) {
  x = 0; char ch = getchar(); int s = 1;
  while (!isdigit(ch)) {
    if (ch == '-') s = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= s;
}

void testOptimized() {
  auto begin = chrono::steady_clock::now();
  for (int i = 0; i < pri.size(); i++)
    write(pri[i]), putchar(' ');
  int a;
  for (int i = 0; i < pri.size(); i++) {
    read(a);
    ++a;
  }
  auto end = chrono::steady_clock::now();
  cout << "\nTest optimized " << echoTime(begin, end) << " seconds.\n";
}

int main() {
  freopen("prime.in", "r", stdin);
  freopen("prime.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(0);
  
  genPrime();
  // -O3 primes within 1e8. Test respectively.
  // testStdio(); //Test stdio 4.689547 seconds.
  // testIostream(); Test iostream 1.37408 seconds.
  testOptimized(); // write non-recursion: Test optimized 2.10872 seconds. Recursion: Test optimized 2.15305 seconds.
  
  return 0;
}