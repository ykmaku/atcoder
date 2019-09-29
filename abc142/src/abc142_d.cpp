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
#include <iomanip>
#include <bitset>


using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<ll> divisor(ll n){
	vector<ll> res;

	for(ll i = 1; i * i <= n; i++){
		if (n % i==0){
			res.push_back(i);
			if (i != n / i){
				res.push_back(n / i);
			}
		}
	}

	// sort(all(res));  //O(\sprt(n)log(n))

	return res;
}


int main()
{
	ll a,b;
	cin>>a>>b;
	if(a>b){
		ll tmp=a;
		a=b;
		b=tmp;
	}
	vector<ll> div_a = divisor(a);

	set<ll> s;
	for(auto x:div_a) if(b%x==0)s.insert(x);
	set<ll> ans;
	ans.insert(1);
	s.erase(1);
	while(!s.empty()){
		ll x = *s.begin();
		ans.insert(x);
		s.erase(x);
		vector<ll> z;
		for(auto y:s)if(gcd(x,y)!=1) z.push_back(y);
		for(auto y:z)s.erase(y);
	}
	// for(auto x:ans)cout<<x<<endl;
	cout<<ans.size()<<endl;

	return 0;
}