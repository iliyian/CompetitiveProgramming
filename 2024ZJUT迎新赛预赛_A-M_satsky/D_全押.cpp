#include<bits/stdc++.h>
using namespace std;using pii=pair<int,int>;const int N=2e5+10,M=1e9+7;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,res=0,lst=0;cin>>n;vector<pii>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].second>>a[i].first;sort(a.begin()+1,a.end());
	//second:左端点 first:右端点 按右端点升排
	for(int i=1;i<=n;i++)if(a[i].second>lst)lst=a[i].first,res++;
	//在未被覆盖的区间中找到最靠左的右端点A,关注A向左的部分(包括其本身)
	//仅选点A显著不劣于其他所有合法方案:若未选点A将任一选点挪到A,否则可移去其他所有选点)
	cout<<res<<'\n';
}