#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(ll i=0;i<(n);++i)
#define repi(i,a,b) for(ll i=ll(a);i<(b);++i)
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
	ll a,b;
	cin>>a>>b;

	map<ll,ll> m;

	repi(n,b+1,a+1){
		ll res=n;
		for (ll x = 2; x*x <= n; x++){
			while(res%x==0)res/=x,m[x]+=1;
		}
		if(res!=1)m[res]+=1;
	}

	ll ans=1;
	for(auto x:m){
		ans*=x.second+1;
		ans%=mod;
	}
	cout<<ans<<endl;


	return 0;
}