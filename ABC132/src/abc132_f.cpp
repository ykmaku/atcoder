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

	vector<ll> a(sqrt_n+10,0);
	repi(i,1,sqrt_n+1){
		a[i] = n/i - (n+i)/(i+1);
	}

	vector<vector<ll>> dp(sqrt_n+10,vector<ll>(k+1,0));
	repi(i,1,sqrt_n+1){
		dp[i][1] = a[i];
	}
	repi(kk,2,k+1){
		repi(i,1,sqrt_n){
			dp[i][kk];
		}
	}

	return 0;
}