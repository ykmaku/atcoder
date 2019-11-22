#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

int main()
{
	int n,t;
	cin>>n>>t;
	vector<P> meal(n);
	rep(i,n)cin>>meal[i].first>>meal[i].second;

	sort(all(meal));

	vector<vector<int>> dp(n+1,vector<int>(t,0));


	rep(i,n){
		repr(j,t-1,0){
			dp[i+1][j] = dp[i][j];
			if(j+meal[i].first>=t) continue;
			else dp[i+1][j+meal[i].first] = max(dp[i+1][j+meal[i].first],dp[i][j]+meal[i].second);
		}
	}

	int ans=0;
	int last=0;
	repr(i,n,1){
		ans = max(ans, dp[i][t-1] + last);
		last = max(last,meal[i-1].second);
	}

	cout<<ans<<endl;

	return 0;
}