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

#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	ll n,k;
	cin>>n>>k;
	vector<int> a(n);
	rep(i,n)cin>>a[i];

	vector<int> b = a;
	sort(all(b));

	ll ans = 0;

	ll xl = (k-1)*k/2;
	xl %= mod;
	ll xr = k*(k+1)/2;
	xr%=mod;
	rep(i,n){
		ll left = 0;
		ll right = 0;
		for (int j = 0; j < i; j++){
			if(a[i]>a[j]) left++;
		}
		for (int j = i+1; j < n; j++){
			if(a[i]>a[j]) right++;
		}
		// cout<<left<<" "<<right<<endl;
		ans+=left*xl;
		ans%=mod;
		ans+=right*xr;
		ans%=mod;
		// ans -= left;
		// ans+=mod;
		// ans%=mod;
	}

	
	cout<<ans<<endl;

	return 0;
}