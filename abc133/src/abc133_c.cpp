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

int main()
{
	ll l,r;
	cin>>l>>r;

	ll dl = l/2019;
	ll dr = r/2019;
	if(dl != dr){
		cout<<0<<endl;
	}else{
		l %= 2019;
		r %= 2019;
		ll ans = 20000;
		for (ll	 i = l; i < r; i++){
			for (ll j = l+1; j <= r; j++){
				ans = min(ans,i*j%2019);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
