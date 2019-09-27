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

int main()
{
	string s;
	cin>>s;
	int n = s.size();

	vector<vector<ll>> dp(n+1,vector<ll>(13,0));

	dp[0][0]=1;
	for (int i = 0; i < n; i++){
		int now = 0;
		if(s[i]=='?') now=-1;
		else now=s[i]-'0';

		for (int digit = 0; digit < 10; digit++){
			if(now!=-1 && now!=digit) continue;
			for (int m = 0; m < 13; m++){
				dp[i+1][(m*10+digit)%13] += dp[i][m];
				dp[i+1][(m*10+digit)%13] %= mod;
			}
		}
	}
	cout<<dp[n][5]<<endl;
	return 0;
}