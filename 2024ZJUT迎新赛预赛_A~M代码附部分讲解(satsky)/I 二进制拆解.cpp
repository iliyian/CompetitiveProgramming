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
��n=i�Ĵ�Ϊf(i) 
{������Ϊn,��a[0]>0������a}����{������Ϊn-1������a}һһ��Ӧ,��ɾһ��a[0]����
��nΪ��ż��,{������Ϊn,��a[0]=0������a}����{������Ϊn/2������a}һһ��Ӧ,ʹ����a[i]��Ϊa[i-1]/a[i+1]����

��˶���������f(i)=f(i-1)+(i%2==0?f(i/2):0);�����f(0)=1
---
��ʵ���Խ�����aת��Ϊ:��0��ʼ,��30��*2�����в�������+1�����Ĳ�������b(��ȥ����0*2��ǰ׺����),a[i]���ж��ٸ�+1��*2����i��
������ɾ����b�����һ��,��ʽ��Ȼ
---
�����ʱ�޸ĳ�500ms�����˱���
*/
