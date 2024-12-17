#include<bits/stdc++.h>
using namespace std;using ll=long long;const int N=2e5+10,M=998244353;
int n;vector<int>a,val;ll res=0;
void sol(int l,int r)
{
	if(l==r)return;int m=l+r>>1;sol(l,m);sol(m+1,r);
	for(int i=m+1,mi=M,ma=0,pa,pi,ps=i;i<=r;i++)
	{
		if(ma<a[i])ma=a[i],pa=i;if(mi>a[i])mi=a[i],pi=i;val[i]=pa;
		while(ps>l&&a[ps-1]<ma&&a[ps-1]>mi)ps--;
		res+=ll(m+1-ps)*max(pa-pi,0);
	}
	ll sum=0;
	for(int i=m,mi=M,ma=0,pa,pi,ps=i,pt=i;i>=l;i--)
	{
		if(mi>a[i])mi=a[i],pi=i;if(ma<a[i])ma=a[i],pa=i;
		while(pt<r&&a[pt+1]>mi)sum+=val[++pt];
		while(ps<r&&a[ps+1]<ma&&a[ps+1]>mi)sum-=val[++ps];
		res+=ll(ps-m)*max(pa-pi,0);res+=sum-ll(pt-ps)*pi;
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;a.resize(n+1);val=a;
	for(int i=1;i<=n;i++)cin>>a[i];sol(1,n);
	for(int i=1;i<=n;i++)a[i]=n+1-a[i];sol(1,n);
	cout<<res<<'\n';
}
/*
(无markdown致歉)
本题在分治之外,部分步骤存在多解(1log,分治2log,树状数组2log…),现给出1log的做法

初步处理:将D<U与D>U的答案分开处理,显然两者本质对称(见57行),做法一致,故以下仅讨论D<U的部分(限制D<U)

考虑分治,对F(l,r)=Σ(i=l⁓r)Σ(j=i⁓r)f(i,j):
l=r时F(l,r)为0,不处理,否则可取mid=(l+r)/2,将其拆解为F(l,mid)+F(mid+1,r)+G(l,r,mid),G(l,r,mid)=Σ(i=l⁓mid)Σ(j={mid+1}⁓r)f(i,j)

如此f(i,j)又可分为3类:

A.D<U<=mid:
从mid开始向左枚举i,易得对于每个i的D与U
而对j的限制为:区间[mid+1,j]中的所有元素值都在[a(D),a(U)]区间中
显然合法的j形成一个前缀,易求最后一个合法的j(设其为ps),且ps随i递减递增;ps-mid即满足条件A的区间个数,每个区间的f=|D-U|

B.D<=mid,U>mid:
同样从mid开始向左枚举i,得对于每个i的D与U(可与A同时处理)
此时对j的限制为:
1.区间[mid+1,j]中的所有元素值都>=a(D)(见A的ps)
2.且存在某元素值>a(U)(类似地,合法的j形成一个后缀,易求第一个合法的j(设其为pt),且pt随i递减递增)
则合法的j形成前缀与后缀的交:区间(ps,pt](可能为空),
需要求的Σ(j={mid+1}⁓r)f(i,j)=Σ(j={mid+1}⁓r)[U(mid+1,j)-D]
预处理U(mid+1,j)即可

C.mid+1<=D<U:
与A本质对称,模仿即可

综上,求单个G(l,r,mid)的复杂度是线性的,为O(r-l)
求Ans=F(1,n)的复杂度为T(n)=2T(n/2)+O(n)=O(nlogn)
*/