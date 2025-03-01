#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define fst first
#define scd second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
using vi = vector<int>;
using vl = vector<ll>;
const ll INF = 1e18 + 7;
const int N = 3e5 + 7;
const int M = 5e8 + 7;
const int modN = 998244353;
const double PI = acos(-1);
mt19937_64 rng(time(0));

int arr[500010];
int num = 0;
int c[500010];
void msort(ll arr[], int left, int right) {
  if (left == right)
    return;
  int mid = left + (right - left) / 2, goal = left;
  int begin1 = left, begin2 = mid + 1, end1 = mid, end2 = right;
  msort(arr, begin1, end1);
  msort(arr, begin2, end2);
  while (begin1 <= end1 && begin2 <= end2) {
    if (arr[begin1] <= arr[begin2]) {
      c[goal++] = arr[begin1++];
    } else {
      c[goal++] = arr[begin2++];
      num += mid - begin1 +
             1; // 此时begin1右侧剩下的左序列的值都比 arr[begin2]大，都是逆序数
    }
  }
  while (begin1 <= end1) {
    c[goal++] = arr[begin1++];
  }
  while (begin2 <= end2) {
    c[goal++] = arr[begin2++];
  }
  for (int i = left; i <= right; i++) {
    arr[i] = c[i];
  }
}

ll a[N];
ll cnt[N];
void solve() {
  ll n;
  cin >> n;
  ll ans = 0, sum = 0;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int r = log2(n) - 1;
  for (int i = r; i >= 0; i--) {
    ll len = (1ll << i), cnt = n / (1ll << i), re = 0;
    for (int j = 0; j < len; j++) {
      for (int k = 0; k < cnt; k += 2) {
        if (a[j + k * len] & len)
          re++;
      }
    }
  }
  num = 0;
  if (sum)
    num++;
  std::cerr << sum << '\n';
  for (int i = 0; i < n; i++)
    a[i] ^= sum;
  msort(a, 0, n - 1);
  cout << num << "\n";
}
signed main() {  ios::sync_with_stdio(false);cin.tie(nullptr);solve();return 0;}
/*
0 1 2 3 4 5 6 7 
1 0 3 2 5 4 7 6 
2 3 0 1 6 7 4 5 
3 2 1 0 7 6 5 4 
4 5 6 7 0 1 2 3 
5 4 7 6 1 0 3 2 
6 7 4 5 2 3 0 1 
7 6 5 4 3 2 1 0 
*/