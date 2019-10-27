#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(ll i=0;i<ll(n);++i)
#define repi(i,a,b) for(ll i=ll(a);i<(b);i++)
#define repr(i,b,a) for(ll i=ll(b);i>=ll(a);i--)
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

vector<ll> fact,inv;

ll f(ll a,ll b, ll p){  // a^b mod pを求める
	if (b == 0)return 1;
	else if (b % 2 == 0){
		ll d = f(a,b/2,p);  //a^b = a^(2k) = (a^k)^2  k = b / 2
		return d * d % mod;
	}else{
		return a * f(a,b-1,p) % mod;
	}
}

void init(ll n){
	fact.resize(n+1,1);
	inv.resize(n+1,1);
	for(int i = 2; i <= n; i++)  //　nまでの階乗を求める
		fact[i] = fact[i-1] * i % mod;
	for(int i = 2; i <= n; i++)  //a^(-1) mod p = a^(p-2) mod p  ここをもう少し早くできるぽい
		inv[i] = f(fact[i],mod-2,mod)%mod;
}

ll comb(ll n,ll k){  //n_C_k
	if (n < k) return 0;
	return (fact[n] * inv[k] % mod) * inv[n-k] % mod;
}


ll calc(ll n,ll k){
	// if (n < k) return 0;
	ll ret=1;
	repi(i,1,k+1){
		ret*=n-i+1;
		ret%=mod;
	}
	ret*=inv[k];
	ret%=mod;
	return ret;
}


int main()
{
	int n;
	cin>>n;
	vector<ll> a(n);
	rep(i,n)cin>>a[i];

	init(3*n);

	ll prev=-1,cnt=0;
	ll ans=1;
	rep(i,n){
		if(a[i]<0){
			if(prev<0)prev=a[i-1];
			cnt++;
		}

		if(prev>0&&a[i]>0){
			
			ll res=calc((a[i]-prev)+cnt,cnt);
			res%=mod;

			ans*=res;
			ans%=mod;
			
			prev=-1;
			cnt=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}