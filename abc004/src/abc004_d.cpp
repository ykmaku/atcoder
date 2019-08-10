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

int main()
{
	ll R,G,B;
	cin>>R>>G>>B;
	ll ans=1LL<<62;
	for (ll g = -300; g <= 300; g++){
		
		ll res = 0;
		for (ll i = g; i < g+G; i++){
			res += abs(i);
		}

		if(g <= -100){
			for (ll i = g-R; i < g; i++){
				res += abs(i+100);
			}
		}else{
			ll l_pos = -100, r_pos = -99;
			for (int i = 0; i < R; i++){
				if(i%2!=0 && r_pos<g) res += abs(r_pos+100),r_pos++;
				else res += abs(100+l_pos),l_pos--;
			}
		}

		if(g+G-1>=100){
			for (ll i = g+G; i < g+G+B; i++){
				res += abs(i-100);
			}
		}else{
			ll l_pos = 99, r_pos = 100;
			for (int i = 0; i < B; i++){
				if(i%2!=0 && l_pos>=g+G) res += abs(100-l_pos),l_pos--;
				else res += abs(r_pos-100),r_pos++;
			}
		}

		// cout<<g<<" "<<res<<endl;
		ans = min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}