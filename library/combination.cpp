#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int lld;

const lld mod = 1e9+7;
const lld INF = 1e9;
const lld MAX = 1e5;

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
	lld h,w;
	scanf("%lld %lld", &w,&h);

	init(h+w-2);

	printf("%lld\n", comb(h+w-2,w-1));  //h_H_w

	return 0;
}