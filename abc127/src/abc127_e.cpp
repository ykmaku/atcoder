#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<ll> fact,inv;

ll f(ll a,ll b, ll p)  // a^b mod pを求める
{
	if (b == 0)
	{
		return 1;
	}else if (b % 2 == 0)
	{
		ll d = f(a,b/2,p);  //a^b = a^(2k) = (a^k)^2  k = b / 2
		return d * d % mod;
	}else
	{
		return a * f(a,b-1,p) % mod;
	}
}

void init(ll n)
{
	fact.resize(n+1,1);
	inv.resize(n+1,1);

	for(int i = 2; i <= n; i++)  //　nまでの階乗を求める
	{
		fact[i] = fact[i-1] * i % mod;
	}
	for(int i = 2; i <= n; i++)  //a^(-1) mod p = a^(p-2) mod p  ここをもう少し早くできるぽい
	{
		inv[i] = f(fact[i],mod-2,mod) % mod;
	}
}

ll comb(ll n,ll k)  //n_C_k
{
	if (n < k)
	{
		return 0;
	}
	return (fact[n] * inv[k] % mod) * inv[n-k] % mod;
}

int main()
{
	ll n,m,k;
	cin>>n>>m>>k;

	init(n*m+10);
	ll ans = 0;

	for (int d = 1; d < m; d++){
		ans += d*(m-d)%mod*(n*n)%mod*comb(m*n-2,k-2);
		ans %= mod;
	}
	for (int d = 1; d < n; d++){
		ans += d*(n-d)%mod*(m*m)%mod*comb(m*n-2,k-2);
		ans %= mod;
	}
	cout<<ans<<endl;

	return 0;
}