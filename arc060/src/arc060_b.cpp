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

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll f(ll b,ll n){
	if(n<b) return n;
	return f(b,n/b) + n%b;
}

int main()
{
	ll n,s;
	cin>>n>>s;
	if(n==s){
		cout<<n+1<<endl;
		return 0;
	}
	ll ans = 1e18;
	for (ll b = 2; b*b <= n; b++){
		if(f(b,n) == s) ans = min(b,ans);
	}

	for (ll p = 1; p*p < n; p++){
		if((n-s)%p!=0) continue;
		ll b = (n-s)/p + 1;
		if(b<2)continue;
		if(f(b,n) == s) ans = min(b,ans);
	}
	if(ans==1e18)ans=-1LL;
	cout<<ans<<endl;
	return 0;
}