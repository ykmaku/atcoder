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
	vector<vector<ll> > dp(n,vector<ll>(13,0LL));
	vector<ll> power(n);
	power[n-1] = 1;
	for (int i = n-2; i >= 0; i--){
		power[i] = 10*power[i+1];
		power[i] %= 13;
	}

	for (int i = n-1; i >= 0; i--){
		if(i==n-1){
			if(s[i]=='?'){
				for (int j = 0; j < 10; j++){
					dp[i][j] = 1;
				}
			}else{
				dp[i][s[i]-'0'] = 1;
			}
			continue;
		}
		if(s[i]=='?'){
			for (ll j = 0; j < 10; j++){
				ll pl = j*power[i];
				pl %= mod;
				for (int k = 0; k < 13; k++){
					ll amari = (pl%13 + (ll)k)%13;
					dp[i][amari] += dp[i+1][k];
					dp[i][amari] %=mod;
				}
			}
		}else{
			ll j = s[i]-'0';
			ll pl = j*power[i];
			pl %= mod;
			for (int k = 0; k < 13; k++){
				ll amari = (pl%13 + (ll)k)%13;
				dp[i][amari] += dp[i+1][k];
				dp[i][amari] %=mod;
			} 
		}
	}

	cout<<dp[0][5]<<endl;

	return 0;
}