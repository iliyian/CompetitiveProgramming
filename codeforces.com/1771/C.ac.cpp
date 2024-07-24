#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> ;

#define ll long long
#define ld long double
#define endl '\n'
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORd(i,b,a) for (int i = b; i >= a; i--)

vector<int> primes;
const int N = 1e3;

void preprocess() {
    bool isPrime[N+1];
    memset(isPrime, true, sizeof(isPrime));
    primes.push_back(2);
    for (int i = 2*2; i <= N; i+=2) {
        isPrime[i] = false;
    }
    for (int i = 3; i <= N; i+=2) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i*i; j <= N; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    int a[n];
    FOR(i,0,n-1) cin >> a[i];
    if (n <= 5) {
        FOR(i,0,n-1) {
            FOR(j,i+1,n-1) {
                if (gcd(a[i], a[j]) > 1)  {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    else {
        for (auto prime : primes) {
            int cnt = 0;
            FOR(i,0,n-1) {
                if (a[i] % prime == 0) cnt++;
                if (cnt > 1) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main() {

    // freopen("data.in", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    /*------------- Code Begins Here --------------*/

    int t = 1;
    cin >> t;
    preprocess();
    for(int test = 1; test <= t; test++) {
        // cout << "Case #" << test << ": ";
        solve();
    }
    
    /*-------------- Code Ends Here ---------------*/ 
    return 0;
}