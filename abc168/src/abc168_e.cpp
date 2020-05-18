#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

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
	ll n;
	cin>>n;
	vector<P> p(n);
	rep(i,n)cin>>p[i].first>>p[i].second;

	map<P,P> mp;
	ll zero = 0;
	rep(i,n){
		if(p[i].first==0 && p[i].second==0){
			zero += 1;
			continue;
		}
		ll x;
		if(p[i].first==0 || p[i].second==0){
			p[i].first = abs(p[i].first);
			p[i].second = abs(p[i].second);
			x = max(abs(p[i].first), abs(p[i].second));
		}else if(p[i].second>0) x = gcd(p[i].first, p[i].second);
		else if(p[i].second<0) x = gcd(-p[i].first, -p[i].second);

		p[i].first /= x;
		p[i].second /= x;

		if(p[i].first < 0){
			p[i].first *= -1;
			p[i].second *= -1;
		}
		if(p[i].first==0)p[i].second = 1;
		if(p[i].second==0)p[i].first = 1;

		if(p[i] == P(1,0)) mp[P(1,0)].first += 1;
		else if(p[i] == P(0,1)) mp[P(1,0)].second += 1;
		else if(p[i].second < 0) mp[P(-p[i].second,p[i].first)].second += 1;
		else mp[p[i]].first += 1;
	}


	ll ans = 1;
	for(auto x: mp){
		
		// cout<<"-----"<<endl;
		// cout<<x.first.first << " " << x.first.second<<endl;
		// cout<<x.second.first<<" "<<x.second.second<<endl;

		P q = x.second;
		ans *= (power(2,q.first) + power(2, q.second) - 1) % mod;
		ans %= mod;
	}

	ans += zero-1 + mod;
	ans %= mod;

	// cout<<ans-1LL<<endl;
	printf("%lld\n", ans);

	return 0;
}