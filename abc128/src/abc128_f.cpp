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
#include <iomanip>
#include <bitset>


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

ll f(int x,vector<ll> &s){
	ll ret = 0;
	int n = s.size();
	ll ma = 0;

	for (int k = 1; k <= (n-1)/x; k++){
		if((n-1)%x==0 &&  n-1-(k-1)*x<=(k-1)*x) break;
		ret += s[n-1-(k-1)*x]+s[(k-1)*x];
		ma = max(ret,ma);
	}
	return ma;
}

int main()
{
	int n;
	cin>>n;
	vector<ll> s(n);
	rep(i,n) cin>>s[i];
	ll ans=0;
	for (int x = 1; x < n; x++){
		ans = max(ans,f(x,s));
	}
	cout<<ans<<endl;
	return 0;
}