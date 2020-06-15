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

ll f(ll n, ll r){
	ll res1 = 1;
	repr(i,n,n-r+1){
		res1 *= ll(i);
		res1 %= mod;
	}

	ll res2 = 1;
	repi(i,1,r+1){
		res2 *= ll(i);
		res2 %= mod;
	}
	return (res1 * power(res2, mod-2))%mod;
}

int main()
{
	ll n,a,b;
	cin>>n>>a>>b;
	cout<<(power(2LL,n) - f(n,a) - f(n,b) - 1 + 10*mod) % mod<<endl;
	return 0;
}