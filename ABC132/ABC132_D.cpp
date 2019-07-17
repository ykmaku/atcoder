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

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

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

ll g(ll k, ll i){
	if(k<i) return 0;
	if(i==1) return 1;
	return comb(k-1,i-1);
}

int main()
{
	ll n,k;
	cin>>n>>k;

	init(2*n);
	ll res = 0;
	for(ll i = 1; i <= k; i++){
		cout<<g(k,i)*comb(n-k+1,i)%mod<<endl;
	}
	return 0;
}