#include<bits/stdc++.h>
using namespace std;using pii=pair<int,int>;const int N=2e5+10,M=1e9+7;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,res=0,lst=0;cin>>n;vector<pii>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].second>>a[i].first;sort(a.begin()+1,a.end());
	//second:��˵� first:�Ҷ˵� ���Ҷ˵�����
	for(int i=1;i<=n;i++)if(a[i].second>lst)lst=a[i].first,res++;
	//��δ�����ǵ��������ҵ������Ҷ˵�A,��עA����Ĳ���(�����䱾��)
	//��ѡ��A�����������������кϷ�����:��δѡ��A����һѡ��Ų��A,�������ȥ��������ѡ��)
	cout<<res<<'\n';
}