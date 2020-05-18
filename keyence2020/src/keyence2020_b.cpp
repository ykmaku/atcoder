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
	vector<P> robot(n), robot_(n);
	rep(i,n){
		ll x,l;
		cin>>x>>l;
		robot[i].second = x-l;
		robot[i].first = x+l;

		// robot_[i].first = x-l+1;
		// robot_[i].second = x+l-1;
	}
	sort(all(robot));
	// sort(all(robot_));
	// reverse(all(robot_));

	ll pos = -INF*2LL;
	int ans = 0;
	rep(i,n){
		if(robot[i].second >= pos){
			ans++;
			pos = robot[i].first;
		}
	}


	// int ans_ = 0;
	// pos = INF*3LL;

	// rep(i,n){
	// 	if(robot_[i].second < pos){
	// 		ans_++;
	// 		pos = robot_[i].first;
	// 	}
	// }
	// ans = max(ans,ans_);
	cout<<ans<<endl;


	return 0;
}