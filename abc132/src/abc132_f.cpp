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
	ll n,k;
	cin>>n>>k;

	ll sqrt_n = ll(sqrt(n));


	vector<ll> num;
	ll cnt = 0;
	for(ll i=1;;i++){
		num.push_back(n/i - n/(i+1));
		cnt += n/i - n/(i+1);
		if(n/(i+1)<=sqrt_n)break;
	}
	rep(i,n-cnt)num.push_back(1);

	int m = num.size();
	reverse(all(num));

	vector<vector<ll>> dp(m,vector<ll>(k,0LL));

	rep(i,m) dp[i][0] = num[i];

	rep(i,k-1){
		vector<ll> sum(m);
		sum[0] = dp[0][i];
		repi(j,1,m)sum[j] = sum[j-1]+dp[j][i], sum[j]%=mod;
		rep(j,m)dp[j][i+1] = sum[m-1-j]*num[j], dp[j][i+1]%=mod;
	}

	ll ans=0;
	rep(i,m){ans+=dp[i][k-1],ans%=mod;}
	cout<<ans<<endl;

	return 0;
}