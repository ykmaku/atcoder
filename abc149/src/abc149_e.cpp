#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

int main()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n);
	rep(i,n)cin>>a[i];

	sort(all(a));
	reverse(all(a));

	ll l = 0;
	while((l+1)*(l+1)<=m)l++;
	l--;

	cout<<l<<endl;

	ll ans = 0;
	ll cnt = 0;
	rep(i,l+1){
		ans += a[i] * (2*(l+1));
		cnt += 1 + 2*(i);
		cout<<"ans = "<<ans<<endl;
		cout<<"cnt = "<<cnt<<endl;
	}

	cout<<endl;

	rep(i,l+1){
		if(cnt+2>m){
			ans += a[i]+a[l+1];
			cnt += 1;
			break;
		}
		ans += 2 *(a[i]+a[l+1]);
		cnt += 2;
		cout<<"ans = "<<ans<<endl;
		cout<<"cnt = "<<cnt<<endl;
	}

	cout<<"cnt = "<<cnt<<endl;
	cout<<ans<<endl;


	return 0;	
}