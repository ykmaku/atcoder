#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(ll i=ll(a);i<(b);i++)
#define repr(i,b,a) for(ll i=ll(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1777777777;
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

ll memo[777777+10]={};
ll func(ll x){
	// if(x==0)return 0;
	if(x==1)return 0;
	if(x==2)return 1;
	if(memo[x]>0)return memo[x];
	memo[x]=((x-1)*(func(x-1)+func(x-2))%mod)%mod;
	return memo[x];
}

int main()
{
	ll n,k;
	cin>>n>>k;

	ll ans=func(k);
	repr(i,n,n-k+1){
		ans*=(i%mod);
		ans%=mod;
	}
	repi(i,1,k+1){
		ans*=power(i,mod-2);
		ans%=mod;
	}
	cout<<ans<<endl;

	return 0;
}