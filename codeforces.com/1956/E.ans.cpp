#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
mt19937 rnd(time(0));
const int MAXN=2e5+5;
int n,a[MAXN];bool b[MAXN];
bool check(){
	a[n+1]=a[1],a[n+2]=a[2],a[n+3]=a[3];
	for(int i=1;i<=n;i++)
		if(a[i]&&a[i+1]&&a[i+2]&&a[i+3]) return true;
	return false;
} 
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==2){
		while(a[1]&&a[2]){
			a[2]=max(0,a[2]-a[1]);
			a[1]=max(0,a[1]-a[2]);
		}
		b[1]=(a[1]>0);b[2]=(a[2]>0);
	}else if(n==3){
		while(a[1]&&a[2]&&a[3]){
			a[2]=max(0,a[2]-a[1]);
			a[3]=max(0,a[3]-a[2]);
			a[1]=max(0,a[1]-a[3]);
		}
		b[1]=(!a[3]&&a[1]);
		b[2]=(!a[1]&&a[2]);
		b[3]=(!a[2]&&a[3]);
	}else{
		while(check()){
			for(int i=1;i<=n;i++) a[i%n+1]=max(0,a[i%n+1]-a[i]);
		}
		for(int i=1;i<=n;i++) b[i]=false;
		auto attack=[&](ll x,ll y){
			ll k=x/y;
			return (2*x-(k+1)*y)*k/2;
		};
		for(int p=1;p<=n;p++) 
			if(a[p]&&a[p%n+1]) a[p%n+1]=max(0,a[p%n+1]-a[p]);
			else break;
		for(int i=1;i<=n;i++) if(!a[i]&&a[i%n+1]){
			b[i%n+1]=true;
			b[(i+2)%n+1]=(a[(i+2)%n+1]>attack(a[(i+1)%n+1],a[i%n+1]));
		}
	}
	int cnt=0;
	for(int i=0;i<=n;i++) if(b[i]) cnt++;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++) if(b[i]) cout<<i<<' ';
	cout<<endl;
}
int main(){
  freopen("E2.in", "r", stdin);
  freopen("E.ans", "w", stdout);
	ios::sync_with_stdio(false);
	int _;cin>>_;
	while(_--) solve();
}