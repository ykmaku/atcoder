#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	int n;
	cin>>n;
	vector<ll> p(n),pos(n+1,0);
	rep(i,n){
		cin>>p[i];
		pos[p[i]] = i+1;
	}
	ll ans = 0;

	set<ll> sl,sr;
	sl.insert(0);
	sr.insert(n+1);
	for (ll now = n; now >= 1; now--){
		ll x_r = *sr.lower_bound(pos[now]);
		sr.erase(x_r);
		sr.insert(n+1);
		ll x_rr = *sr.lower_bound(x_r);
		sr.insert(x_r);

		ll x_l = *sl.lower_bound(-pos[now]);
		sl.erase(x_l);
		sl.insert(0);
		ll x_ll = *sl.lower_bound(x_l);
		sl.insert(x_l);

		x_l *=-1;
		x_ll *= -1;

		ans += now*(x_r-pos[now])*(x_l-x_ll);
		ans += now*(x_rr-x_r)*(pos[now]-x_l);

		sr.insert(pos[now]);
		sl.insert(-1*pos[now]);
	}
	cout<<ans<<endl;
	
	return 0;
}