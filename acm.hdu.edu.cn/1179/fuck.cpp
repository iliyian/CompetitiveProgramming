#include<bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 1e5 + 10;
int n, k;
int a[N], A[N];
int b[N], B[N];
int s[N];

int find(int *a) {
    rep(i, 0, n - 1) s[i] = a[i + 1];

    int i = 0, j = 1, k = 0;
    for(; i < n && j < n && k < n; ) 
        if(s[(i + k) % n] == s[(j + k) % n])
            k ++;
        else {
            s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j) i++;
            k = 0;
        }
    
    return min(i, j) + 1;
}

int c[N];
void add(int x) {for(; x <= n; x += (x & -x)) c[x] ++;}
int ask(int x) {int s = 0; for(; x; x -= (x & -x)) s += c[x]; return s;}

int work(int *a) {
    int s = 0;
    rep(i, 1, n) c[i] = 0;
    per(i, n, 1) {
        int x = lower_bound(A + 1, A + n + 1, a[i]) - A;
        s ^= (ask(x) & 1);
        add(x);
    }
    return s;
}

void solve() {
    n = read(), k = read();
    rep(i, 1, n) a[i] = A[i] = read();
    rep(i, 1, n) b[i] = B[i] = read();

    sort(A + 1, A + n + 1);
    sort(B + 1, B + n + 1);

    bool flag = true;
    rep(i, 1, n) if(A[i] != B[i]) {flag = false; break;}

    if(!flag) return puts("NO"), void();

    if(n == k) {
        int i = find(a);
        int j = find(b);

        bool flag = true;
        rep(k, 1, n) {
            int x = i + k - 1 > n ? i + k - 1 - n : i + k - 1;
            int y = j + k - 1 > n ? j + k - 1 - n : j + k - 1;
            if(a[x] != b[y]) {flag = false; break;}
        }
        return puts(flag ? "YES" : "NO"), void();
    }

    if(k == 1) {
        bool flag = true;
        rep(i, 1, n) if(a[i] != b[i]) {flag = false; break;}
        return puts(flag ? "YES" : "NO"), void();
    }

    if(!(k&1)) return puts("YES"), void();

    rep(i, 1, n - 1) if(A[i] == A[i + 1]) {puts("YES"); return;}

    int i = work(a);
    int j = work(b);

    puts(i == j ? "YES" : "NO");
}

int main() {
	int T = read(); while(T --) solve(); return 0;
}