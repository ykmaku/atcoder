#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

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
	int n,p;
	cin>>n>>p;
	vector<P> item(n);
	rep(i,n)cin>>item[i].first>>item[i].second;
	sort(all(item),[&](P p1,P p2){return p1.first<p2.first;});

	// rep(i,n)cout<<item[i].first<<" "<<item[i].second<<endl;
	vector<vector<ll>> dp(n+1,vector<ll>(p+1,0));
	repr(i,n-1,0){
		rep(j,p+1){
			if(j>=item[i].first){
				dp[i][j]=max(dp[i+1][j],dp[i+1][j-item[i].first]+item[i].second);
			}else{
				dp[i][j]=dp[i+1][j];
			}
		}
	}

	ll ans=0;

	rep(i,n)ans=max(ans,dp[i][p]+(i>0?item[i-1].second:0));
	// rep(i,n)cout<<dp[i][p]<<endl;;
	cout<<ans<<endl;

	return 0;
}