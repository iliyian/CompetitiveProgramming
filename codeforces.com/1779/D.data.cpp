// Reference: https://codeforces.com/blog/entry/62393

#include <bits/stdc++.h>
using namespace std;

mt19937 rng(1779);

int randint(int a, int b) {
    uniform_int_distribution<int> dist(a, b);
    return dist(rng);
}

int main() {
  freopen("D.in", "w", stdout);
    const int p = 20753;
    int t = 1+(200000-1)/p;
    int rem = 200000;
    printf("%d\n", t);
    for (int caseno = 0; caseno < t; caseno++) {
        int n = min(p, rem);
        int m = n;
        rem -= p;

        printf("%d\n", n);

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = i*p+1;
        }

        for (int i = 0; i < n; i++) {
            printf("%d%c", a[i], (i==(n-1)) ? '\n' : ' ');
        }
        for (int i = 0; i < n; i++) {
            printf("%d%c", a[i], (i==(n-1)) ? '\n' : ' ');
        }
        printf("%d\n", m);
        for (int i = 0; i < n; i++) {
            printf("%d%c", a[i], (i==(n-1)) ? '\n' : ' ');
        }
    }

    return 0;
}

