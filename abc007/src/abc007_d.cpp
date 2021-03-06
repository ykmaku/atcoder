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

ll f(ll x){
	vector<vector<vector<ll>>> dp(20,vector<vector<ll>>(2,vector<ll>(2,0)));
	string s = to_string(x);
	int l = s.length();

	dp[0][0][0] = 1;

	for (int i = 0; i < l; i++){
		int D = s[i] - '0';
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 2; k++){
				for (int d = 0; d <= (j?9:D); d++){
					dp[i+1][j||(d<D)][k||(d==4)||(d==9)] += dp[i][j][k]; 
				}
			}
		}
	}

	return dp[l][0][1] + dp[l][1][1];
}

int main()
{
	ll a,b;
	cin>>a>>b;
	cout<<f(b)-f(a-1)<<endl;

	return 0;
}