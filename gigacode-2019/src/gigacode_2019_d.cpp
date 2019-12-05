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
	int H,W;
	ll K,V;
	cin>>H>>W>>K>>V;
	vector<vector<ll>> a(H,vector<ll>(W));
	rep(i,H)rep(j,W)cin>>a[i][j];

	vector<vector<ll>> sum(H+1,vector<ll>(W+1,0LL));
	repi(i,1,H+1)repi(j,1,W+1){
		sum[i][j] = sum[i][j-1]+a[i-1][j-1];
	}

	rep(i,H)rep(j,W+1){
		sum[i+1][j] += sum[i][j];
	}

	ll ans = 0;
	repi(h1,1,H+1)repi(h2,h1,H+1)repi(w1,1,W+1)repi(w2,w1,W+1){
		ll s = (h2-h1+1)*(w2-w1+1);
		ll value = sum[h2][w2] - sum[h2][w1-1] - sum[h1-1][w2] + sum[h1-1][w1-1];
		ll res = value+s*K;
		if(res>V)continue;
		ans = max(ans,s);
	}
	cout<<ans<<endl;

	return 0;
}