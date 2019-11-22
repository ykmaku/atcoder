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
	int n,k;
	cin>>n>>k;
	vector<ll> h(n+1,0);
	repi(i,1,n+1)cin>>h[i];

	if(n==k){
		cout<<0<<endl;
		return 0;
	}

	vector<vector<ll>> dp(n+1,vector<ll>(n+1,1LL<<60));

	dp[0][0]=0;

	repi(i,1,n+1){
		repi(j,1,i+1){
			repi(l,1,i+1){
				dp[i][j] = min(dp[i][j], dp[i-l][j-1]+max(0LL,h[i]-h[i-l]));
			}
		}
	}

	ll ans=1LL<<60;
	rep(i,n+1) ans=min(ans, dp[i][n-k]);

	cout<<ans<<endl;

	// rep(i,n+1){
	// 	rep(j,n+1)cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	
	return 0;
}