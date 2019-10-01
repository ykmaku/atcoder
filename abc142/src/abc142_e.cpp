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

#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	int n,m;
	cin>>n>>m;
	vector<pair<ll,vector<ll>>> key;
	set<int> s;
	rep(i,m){
		ll a,b;
		cin>>a>>b;
		vector<ll> x(b);
		rep(j,b)cin>>x[j],s.insert(x[j]);
		key.push_back(pair<ll,vector<ll>>(a,x));
	}

	if(s.size()!=n){
		cout<<-1<<endl;
		return 0;
	}

	vector<vector<ll>> dp((1<<n),vector<ll>(m+1,1e15));
	dp[0][0] = 0;
	for (int i = 1; i <= m; i++){
		ll s = 0;
		for(auto x:key[i-1].second) s |= (1<<(x-1));
		rep(j,(1<<n)) dp[j][i] = dp[j][i-1];
		rep(j,(1<<n)){
			dp[s|j][i] = min(dp[s|j][i], dp[j][i-1]+key[i-1].first);
		}
	}

	cout<<dp[(1<<n)-1][m]<<endl;

	return 0;
}