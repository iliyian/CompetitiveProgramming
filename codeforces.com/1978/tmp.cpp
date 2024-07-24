#include <bits/stdc++.h>
using namespace std;
int akm(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return akm(m - 1, 1);
    return akm(m - 1, akm(m, n - 1));
}
int main() {
    int n = 15, m = 3;
    auto begin = chrono::high_resolution_clock::now();
    cout << akm(m, n) << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cout << "Used "
      << double(duration.count()) * chrono::nanoseconds::period::num / chrono::nanoseconds::period::den
      << " Seconds";
    return 0;
}
