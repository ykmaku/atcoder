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

ll dp[10010][2][110] = {};

int main()
{
	string k;
	int d;
	cin>>d>>k;
	
	int l = k.length();
	dp[0][0][0] = 1;
	for (int i = 0; i < l; i++){
		int D = k[i]-'0';
		for (int smaller = 0; smaller < 2; smaller++){
			for (int j = 0; j < d; j++){
				for (int digit = 0; digit <= (smaller?9:D); digit++){
					dp[i+1][smaller||(digit<D)][(j+digit)%d] += dp[i][smaller][j];
					dp[i+1][smaller||(digit<D)][(j+digit)%d] %= mod;
				}
			}
		}
	}
	cout<<(dp[l][0][0] + dp[l][1][0]-1+mod)%mod<<endl;
	return 0;
}