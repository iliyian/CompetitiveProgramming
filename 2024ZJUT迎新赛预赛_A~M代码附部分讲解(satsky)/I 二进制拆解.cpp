#include<bits/stdc++.h>
using namespace std;using ll=long long;const int N=1e6,M=998244353;
int dp[N+10];
int sum(int a,int b){a+=b;return a-(a>=M?M:0);}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	dp[0]=1;for(int i=1;i<=N;i++)dp[i]=(i&1)?dp[i-1]:sum(dp[i-1],dp[i/2]);
	int t=1;cin>>t;while(t--){int x;cin>>x;cout<<dp[x]<<'\n';}
}
/*
设n=i的答案为f(i) 
{运算结果为n,且a[0]>0的序列a}可与{运算结果为n-1的序列a}一一对应,增删一个a[0]即可
若n为正偶数,{运算结果为n,且a[0]=0的序列a}可与{运算结果为n/2的序列a}一一对应,使所有a[i]变为a[i-1]/a[i+1]即可

因此对于正数有f(i)=f(i-1)+(i%2==0?f(i/2):0);特殊地f(0)=1
---
其实可以将序列a转化为:从0开始,在30次*2操作中插入若干+1操作的操作序列b(再去掉对0*2的前缀部分),a[i]即有多少个+1被*2操作i次
考虑增删序列b的最后一步,上式显然
---
特意把时限改成500ms卡掉了背包
*/
