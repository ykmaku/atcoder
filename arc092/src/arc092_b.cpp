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
	vector<ll> a(n),b(n);
	rep(i,n)cin>>a[i];
	rep(i,n)cin>>b[i];

	ll ans = 0;
	rep(k,29){
		ll target = 1<<k;
		ll m = target*2;
		vector<ll> b2=b,a2=a;
		rep(i,n) b2[i]%=m,a2[i]%=m;
		sort(all(b2));
		int cnt = 0;
		rep(i,n){
			int l = lower_bound(all(b2),target-a2[i])-b2.begin();
			int r = lower_bound(all(b2),2*target-a2[i])-b2.begin();
			cnt += r-l;

			l = lower_bound(all(b2),3*target-a2[i])-b2.begin();
			r = lower_bound(all(b2),4*target-a2[i])-b2.begin();

			cnt += r-l;
		}
		if(cnt%2!=0) ans += target;
	}

	cout<<ans<<endl;

	return 0;
}