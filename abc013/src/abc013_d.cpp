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
	int n,m,d;
	cin>>n>>m>>d;
	vector<int> a(m);
	rep(i,m) cin>>a[i],a[i]--;

	vector<int> moved(n);
	iota(all(moved),0);
	rep(i,m){
		int target = a[i];
		int tmp = moved[target+1];
		moved[target+1] = moved[target];
		moved[target] = tmp;
	}

	vector<vector<int> > dp(32,vector<int>(n));
	rep(i,n) dp[0][moved[i]] = i;
	rep(i,31){
		rep(j,n){
			dp[i+1][j] = dp[i][dp[i][j]];
		}
	}

	vector<int> ans(n);

	rep(i,n){
		int pos = i;
		int cnt = 0;
		while(1){
			if((d>>cnt)==0) break;
			if((d>>cnt)&1){
				pos = dp[cnt][pos];
			}
			cnt++;
		}
		ans[i] = pos;
	}

	rep(i,n) cout<<ans[i]+1<<endl;
	
	return 0;
}