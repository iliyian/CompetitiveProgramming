#include<bits/stdc++.h>
using namespace std;using ll=long long;const int N=1e6+10;const ll inf=1e17;
/*
b[i]<=b[i+1]是肯定的,没必要交换顺序;于是"连续"等价于b[1]=1,b[i+1]-b[i]=[0,1]
画出c[i]=b[i]-a[i]的折线,我们需要使折线上的整点1⁓n到x轴的距离总和最小
先设所有b[i]-b[i-1](i≥2)为1得标准折线,再将若干b[i]调整为0,效果为c[i⁓n]-=1

纯分析会比较绕,注意到(?!):将a,b抽象为一些数轴上的点调整前后的位置,
若一个点调整后与前一个点重叠(b[i]-b[i-1]=0),则这个点一定没移动过(a[i]=b[i])
(b[i]已经有其他点在了,那点i大可待在原位)

于是,a[i]=b[i](c[i]=0)是b[i]-b[i-1]=0(可调整)的必要条件;
若从左到右操作,要求点i调整(c[i⁓n]-=1)后必须有c[i]=0

计数c[i⁓n]中≤c[i](i⁓n折线上高度不高于i)的点个数(fx(c[i])),稍作处理得调整点i对答案的贡献(val[i])
现只需选择序列1⁓n的一个子序列R;设R的第i位为R[i],要求标准折线中的c[R[i]]=i,且最大化val[R[i]]的总和;剩余部分显然
---
这份代码中fx函数的总复杂度为O(n),本做法复杂度为线性(甚至只用到了数组,谁都可以写!)
由于本题n≤1e6,你可以将fx替换为树状数组,见std2
还有其他的做法,不再展开
*/
struct S
{
	int n,E=0,pt=0,pv=0;ll sum=0,ans=0;vector<int>a,c,cnt,val,pre,lst;vector<ll>dp;
	int fx(int v)
	{
		int v2=max(v,0);
		while(pt<v2)pv-=cnt[pt],pt++;
		while(pt>v2)pt--,pv+=cnt[pt];
		if(v>=0)cnt[pt]++,pv++;return pv;
	}
	void ini()
	{
		cin>>n;a.resize(n+1,0),c=cnt=val=pre=lst=a;dp.resize(n+2,-inf);dp[0]=0;
		for(int i=1;i<=n;i++)cin>>a[i];//sort(a.begin()+1,a.end());
		for(int i=1;i<=n;i++)c[i]=i-a[i],sum+=abs(c[i]);
		for(int i=n;i;i--)val[i]=fx(c[i])*2-(n-i+1);
		for(int i=1;i<=n;i++)if(c[i]>0)
		{
			int x=c[i];ll v=dp[x-1]+val[i];
			if(dp[x]>v)continue;dp[x]=v;pre[i]=lst[x-1];lst[x]=i;
			if(ans>dp[x])continue;ans=dp[x],E=i;
		}
		cout<<sum-ans<<'\n';
		vector<int>b(n+1,1);while(E)b[E]=0,E=pre[E];b[0]=0;
		for(int i=1;i<=n;i++)cout<<(b[i]+=b[i-1])<<" \n"[i==n];
	}
	void solve()
	{

	}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t=1;//cin>>t;
	while(t--){S SS;SS.ini();SS.solve();}
}