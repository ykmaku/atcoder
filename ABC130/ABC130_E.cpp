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

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> s(n+1),t(m+1);
	s[0] = -1;t[0]=-1;
	for (int i = 1; i <= n; i++){
		cin>>s[i];
	}
	for (int i = 1; i <= m; i++){
		cin>>t[i];
	}
	
	vector<vector<ll> > dp(max(n,m)+2,vector<ll>(max(n,m)+2,0));
	for (int i = 0;i <= n; i++){
		dp[i][0] = 1;
	}
	for (int i = 0; i <= m; i++){
		dp[0][i] = 1;
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			dp[i][j] = (s[i]==t[j]?dp[i][j-1]+dp[i-1][j]:(dp[i][j-1]+dp[i-1][j])%mod-dp[i-1][j-1]+mod);
			dp[i][j] %= mod;
		}	
	}
	cout<<dp[n][m]<<endl;
	
	return 0;
}
