#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 998244353;
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
	ll n, s;
	cin>>n>>s;
	vector<ll> a(n);
	rep(i,n)cin>>a[i];

	vector<ll> dp(3030,0);
	ll ans=0;
	rep(i,n){
		repr(j,s,a[i]){
			if(j==a[i]){
				dp[j] += i+1;
				dp[j] %= mod;
			}else{
				dp[j] += dp[j-a[i]];
				dp[j] %= mod;
			}
		}
		ans += dp[s];
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}