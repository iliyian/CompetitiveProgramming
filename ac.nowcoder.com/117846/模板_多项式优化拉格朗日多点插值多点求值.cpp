/*

LLLLLLLLLLL             IIIIIIIIIIYYYYYYY       YYYYYYYIIIIIIIIII               AAA               NNNNNNNN        NNNNNNNN
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I              A:::A              N:::::::N       N::::::N
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I             A:::::A             N::::::::N      N::::::N
LL:::::::LL             II::::::IIY::::::Y     Y::::::YII::::::II            A:::::::A            N:::::::::N     N::::::N
  L:::::L                 I::::I  YYY:::::Y   Y:::::YYY  I::::I             A:::::::::A           N::::::::::N    N::::::N
  L:::::L                 I::::I     Y:::::Y Y:::::Y     I::::I            A:::::A:::::A          N:::::::::::N   N::::::N
  L:::::L                 I::::I      Y:::::Y:::::Y      I::::I           A:::::A A:::::A         N:::::::N::::N  N::::::N
  L:::::L                 I::::I       Y:::::::::Y       I::::I          A:::::A   A:::::A        N::::::N N::::N N::::::N
  L:::::L                 I::::I        Y:::::::Y        I::::I         A:::::A     A:::::A       N::::::N  N::::N:::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I        A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I       A:::::::::::::::::::::A     N::::::N    N::::::::::N
  L:::::L         LLLLLL  I::::I         Y:::::Y         I::::I      A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N
LL:::::::LLLLLLLLL:::::LII::::::II       Y:::::Y       II::::::II   A:::::A             A:::::A   N::::::N      N::::::::N
L::::::::::::::::::::::LI::::::::I    YYYY:::::YYYY    I::::::::I  A:::::A               A:::::A  N::::::N       N:::::::N
L::::::::::::::::::::::LI::::::::I    Y:::::::::::Y    I::::::::I A:::::A                 A:::::A N::::::N        N::::::N
LLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIII    YYYYYYYYYYYYY    IIIIIIIIIIAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNN

 * 
 * ==============================================================================
 * @Author : iliyian
 * @File   : 模板_多项式优化拉格朗日多点插值多点求值.cpp
 * @Time   : 2025-10-24 19:32:45
 * ==============================================================================
*/

#include <bits/stdc++.h>
// #define int long long
using namespace std;

#define add(x, y) ((x) + (y) >= mod ? (x) + (y) - mod : (x) + (y))
#define mus(x, y) ((x) < (y) ? (x) - (y) + mod : (x) - (y))
#define div2(x) (((x) & 1) ? (((x) + mod) >> 1) : ((x) >> 1))
#define vec vector<int> 

constexpr int mod = 998244353;


	void out(vec x){
		
		for(int i = 0; i <= x.size() - 1; i ++)
			cout << x[i] << " ";
		cout << endl;
	}
	
namespace poly{
	
	
	const int maxn = 1e6+10;
	int rev[maxn], revv = 0;
	int inv[maxn], invv = 1;
	
	vector<int> none;
	vector<int> roots{0, 1};
	
	inline int quickpow(int x, int b, int mod){
		int j = 1;
		for(; b; b >>= 1, x = 1ll * x * x % mod)
			if(b & 1) 
				j = 1ll * j * x % mod;
		return j % mod;
	}
	
	void getrev(int n){ //计算蝴蝶变换的序列
		
		if(revv == n) return ;
	
		revv = n;
		int k = __builtin_ctz(n) - 1;
	    for(int i = 0; i < n; i ++)
	        rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
	}
	
	void getinv(int n){
		
		if(invv >= n) return ;
		inv[1] = 1;
		
		for(int i = invv + 1; i <= n; i ++)
			inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
		invv = n;	
	}
	
	void dft(vec &a) {
	    int n = a.size();
		getrev(n);
	    
		for (int i = 0; i < n; i++)
	        if (rev[i] < i) swap(a[i], a[rev[i]]);
	    
	    if (int(roots.size()) < n) {
	        int k = __builtin_ctz(roots.size());
	        roots.resize(n);
	        while ((1 << k) < n) {
	            int e = quickpow(3, (mod - 1) >> (k + 1), mod); // 这里的 3 是 mod 的原根 
	            for (int i = 1 << (k - 1); i < (1 << k); i ++) {
	                roots[i << 1] = roots[i];
	                roots[i << 1 | 1] = 1ll * roots[i] * e % mod;
	            }
	            k ++;
	        }
	    }
	    for (int k = 1; k < n; k <<= 1) {
	        for (int i = 0; i < n; i += (k << 1)) {
	            for (int j = 0; j < k; j ++) {
	                int u = a[i + j];
	                int v = 1ll * a[i + j + k] * roots[k + j] % mod;
	                a[i + j] = add(u, v);
	                a[i + j + k] = mus(u, v);
	            }
	        }
	    }
	}
	
	void idft(vec &a) {
	    int n = a.size();
	    reverse(a.begin() + 1, a.end());
	    dft(a);
	    int inv = quickpow(n, mod - 2, mod);
	    for (int i = 0; i < n; i ++) {
	        a[i] = 1ll * a[i] * inv % mod;
	    }
	}
	
	vec operator * (vec a, vec b) {
	    if (a.size() == 0 || b.size() == 0) {
		    return none;
	    }
	    
	    int sz = 1, tot = a.size() + b.size() - 1;
	    while (sz < tot) sz *= 2;
	    
	    a.resize(sz);
	    b.resize(sz);
	    dft(a);
	    dft(b);
	    for (int i = 0; i < sz; i ++) {
	        a[i] = 1ll * a[i] * b[i] % mod;
	    }
	    idft(a);
	    a.resize(tot);
	    
		for(int i = 0; i < a.size(); i ++)
	    	if(a[i] < 0) a[i] += mod;
	    	
	    return a;
	}
    
    vec Multiply(vec a, vec b, int len = -1){
    	if(len == -1) return a * b;
    	vec ret = a * b;
    	ret.resize(len);
    	return ret;
	}
    
	vec ChaMultiply(int n, vec A, vec B){
		//多项式差卷积： 
		//Ret[k] = Sum(x = k~n) A[x - k] * B[x];
		A.resize(n + 1);
		B.resize(n + 1);
		reverse(B.begin(), B.end());
		vec Ans = Multiply(A, B);
		Ans.resize(n + 1);
		reverse(Ans.begin(), Ans.end());
		return Ans;
	}	 
	   
	vec operator - (vec a, const vec &b){
		
		a.resize(max(a.size(), b.size()));
		
		for(int i = 0; i < b.size(); i ++)
			a[i] = mus(a[i], b[i]);
		
		return a;
	}
	
	vec operator + (vec a, const vec & b){
		a.resize(max(a.size(), b.size()));
		
		for(int i = 0; i < b.size(); i ++)
			a[i] = add(a[i], b[i]);
		
		return a;
	}
	
	vec Deriv(vec a){//求导 
		if(a.empty()) return none;
		
	    for(int i = 1; i < a.size(); i ++)
	        a[i - 1] = 1ll * a[i] * i % mod;
	    a.pop_back();
	    return a;
	}
	
	vec Integ(vec a){//积分 
		if(a.empty()) return none;
		
	    a.push_back(0);
	    getinv(a.size() - 1);
	    for(int i = a.size() - 1; i > 0; i --)
	        a[i] = 1ll * a[i - 1] * inv[i] % mod;
	    a[0] = 0;
	    
	    return a;
	}
	
	
	
	vec cut(vec x, int m){
		if(x.size() > m)
			x.resize(m);
		return x;
	}
	
	vec GetInv(vec a, int len = -1){
		
	    if(len == -1)	len = a.size();
		vec ret(1, quickpow(a[0], mod - 2, mod));
	    
	    for(int l = 4; (l >> 2) < len; l <<= 1 ){
	    	
	        getrev(l);
	        vec tmp(a);
	        tmp.resize(l >> 1);
	        tmp.resize(l);	dft(tmp); 
	        ret.resize(l);	dft(ret);
	        
			for(int i = 0; i < l; i ++)
	            ret[i] = (2 + mod - 1ll * tmp[i] * ret[i] % mod) * ret[i] % mod;
		
			idft(ret);
	        ret.resize(l >> 1);
	    }
	    
	    ret.resize(len);
	    
	    return ret;
	}
	
	vec GetLn(vec a, int len = -1){ //对数，需满足f(0) = 1
	    if(len == -1)	len = a.size();
	    a = Integ(Deriv(a) * GetInv(a, len));
	    a.resize(len);
	    return a;
	}
	
	vec GetExp(vec a,int len = -1){ //指数，需满足f(0) = 0
	
	    if(len == -1)	len = a.size();
	    vec b(1, 1), c;
	    int n = a.size();
	    for(int l = 2; (l >> 1) < len; l <<= 1){
	        c = GetLn(b, l);
	        for(int i = 0; i < l; i ++)
	            c[i] = (i < n) ? mus(a[i], c[i]) : mus(0, c[i]);
	        c[0] = add(c[0], 1);
	        
	        b = b * c;
	        b.resize(l);
	    }
	    
	    b.resize(len);
	    return b;
	}
	
	vec GetSqrt(vec a, int len = -1){ //多项式开根，这里只实现了f(0) = 1的情况，若不等于1需要先算二次剩余
	    if(len == -1)	len = a.size();
	    vec ret(1, 1);
	    
	    for(int l = 4; (l >> 2) < len; l <<= 1){
	        getrev(l);
	        vec tmp(a);
	        tmp.resize(l >> 1);
	        tmp.resize(l);	dft(tmp);
	        vec tt(GetInv(ret, l >> 1));
	        tt.resize(l);	dft(tt);
	        
	        for(int i = 0; i < l; i ++)
	            tmp[i] = 1ll * tmp[i] * tt[i] % mod;
	        
	        idft(tmp);
	        ret.resize(l >> 1);
	        for(int i = 0; i < (l >> 1); i ++){
	        	ret[i] = add(ret[i], tmp[i]);
	        	ret[i] = div2(ret[i]);
			}
	            
	    }
	    
	    ret.resize(len);
	
	    return ret;
	}
	
	
	vec GetInvSum(vec a){
		
		int n = a.size() - 1;
		vec s(n + 1), sinv(n + 1);
		
		s[0] = a[0];
		for(int i = 1; i <= n; i ++)
			s[i] = 1ll * s[i - 1] * a[i] % mod;
		sinv[n] = quickpow(s[n], mod - 2, mod);
		
		for(int i = n - 1; i >= 0; i --)
			sinv[i] = 1ll * sinv[i + 1] * a[i + 1] % mod;
		
		for(int i = 1; i <= n; i ++)
			sinv[i] = 1ll * sinv[i] * s[i - 1] % mod;
			
		return sinv;
	}
		
	vec InterP, InterPxi, Q[maxn], P[maxn];// ling : 多项式快速多点求值和快速插值 
		
	vec MulT(vec a, vec b){// ling : 玄学的转置乘法 
		int n = a.size(), m = b.size();
		reverse(b.begin(), b.end());
		b = a * b;
		for(int i = 0; i <= n - 1; i ++)
			a[i] = b[i + m - 1];
		return a;
	}
	
	void Init(vec &A, int k, int l, int r){
		
		if(l == r){
			Q[k].resize(2);
			Q[k][0] = 1, Q[k][1] = (mod - A[l]);
			return ;
		}
		
		int mid = (l + r) >> 1;
		Init(A, k << 1, l, mid), Init(A, k << 1 | 1, mid + 1, r);
		Q[k] = Q[k << 1] * Q[k << 1 | 1];
		return ;
	}
	
	void Multipoints(int k, int l, int r, vec F, vec &g){
		F.resize(r - l + 1);
		if(l == r)  return void(g[l] = F[0]);
		int mid = (l + r) >> 1;
		
		Multipoints(k << 1, l, mid, MulT(F, Q[k << 1 | 1]), g);
		Multipoints(k << 1 | 1, mid + 1, r, MulT(F, Q[k << 1]), g);
	}
	
	void Multipoint(vec f, vec a, vec &v, int n){ 
		f.resize(n + 1), a.resize(n);
		// ling ；调用此函数进行多项式多点快速求值 
		// f : 系数数组， a ： 所求自变量数组 ， v 与自变量对应的最终答案数组 
		// n = max（多项式项数，所求点数量） 
		// 			↑项数 = 模指 + 1  
		for(int i = 0; i < a.size(); i ++)
			a[i] %= mod;
		
		Init(a, 1, 0, n - 1), v.resize(n);
		Multipoints(1, 0, n - 1, MulT(f, GetInv(Q[1], n + 1)), v);
		return ;
	}
	
	void GetP(int p, int l, int r, const vec &xi){ // P(x) = PAI (0 <= i <= n - 1) (x - xi)
		
		if(l == r){
			P[p].resize(2);
			P[p][0] = -xi[l], P[p][1] = 1; // x - xi[i]
			return ;
		}
		
		int mid = l + r >> 1;
		
		GetP(p << 1, l, mid, xi);
		GetP(p << 1 | 1, mid + 1, r, xi);
		P[p] = P[p << 1] * P[p << 1 | 1];
	}

	
	vec InterPart(int p, int l, int r, const vec &xi, const vec &yi, const vec &InterPxi){
		
		if(l == r){	
			vec ret;
			ret.push_back(1ll * yi[l] * InterPxi[l] % mod);
			return ret;
		}
		
		int mid = l + r >> 1;
		
		return InterPart(p << 1, l, mid, xi, yi, InterPxi) * P[p << 1 | 1]
			+ InterPart(p << 1 | 1, mid + 1, r, xi, yi, InterPxi) * P[p << 1];
	}



	void Interpolation(const vec &xi, const vec &yi, vec &f){
			
		// ling 调用此函数进行多项式快速插值 
		// x, y 已知横纵坐标 
		// f 返回的系数数组
		
		GetP(1, 0, xi.size() - 1, xi);
		
		InterP = Deriv(P[1]); 
		
		Multipoint(InterP, xi, InterPxi, xi.size());
		
		InterPxi = GetInvSum(InterPxi); // InterPxi -> InvInterPxi
		f = InterPart(1, 0, xi.size() - 1, xi, yi, InterPxi);
		return ; 
	}


	void ContinInter(const vec &yi, vec &ans, int m){ 
		// ling : n 次多项式 给定f(0 ~ n) and m, ask f(m + 0 ~ m + n)
		
		int n = yi.size() - 1;
		
		vec invfac(n + 1);	invfac[0] = 1;
		for(int i = 1; i <= n; i ++)
			invfac[i] = 1ll * invfac[i - 1] * i % mod;
		invfac = GetInvSum(invfac);
			
		vec A(n + 1), B(n << 1 | 1);
		for(int i = 0; i <= n; i ++)
			A[i] = 1ll * yi[i] 
				* ((n - i & 1) ? (mod - 1) : 1) % mod 
				* invfac[i] % mod 
				* invfac[n - i] % mod;
			
		for(int i = 0; i <= (n << 1); i ++)
			B[i] = add(i + m - n, mod);
		B = GetInvSum(B);
	
		ans = A * B;
		
		ans.resize(n << 1 | 1);
		
		reverse(ans.begin(), ans.end());
		for(int i = 0; i <= n - 1; i ++)
			ans.pop_back();
		reverse(ans.begin(), ans.end());
		
		vec t(n + 1); t[0] = 1;
		vec it(n + 1); it[0] = 1;
		for(int i = 1; i <= n; i ++)
			it[i] = m + i - n - 1;
		it = GetInvSum(it);
		
		for(int i = m - n; i <= m; i ++)
			t[0] = 1ll * t[0] * i % mod;
		for(int i = 1; i <= n; i ++)
			t[i] = 1ll * t[i - 1] 
					* (m + i) % mod 
					* it[i] % mod;
		
		for(int i = 0; i <= n; i ++)
			ans[i] = 1ll * ans[i] * t[i] % mod;
	}

}


void solve() {
  int n;
  std::cin >> n;
  std::vector<int> f, x(n), y(n);
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  poly::Interpolation(x, y, f);
  for (auto i : f) {
    std::cerr << i << ' ';
  }
  int q;
  std::cin >> q;
  std::vector<int> ask(q), ans(q);
  for (int i = 0; i < q; i++) {
    std::cin >> ask[i];
  }
  poly::Multipoint(f, ask, ans, 9);
  for (int i = 0; i < q; i++) {
    std::cout << ans[i] << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
