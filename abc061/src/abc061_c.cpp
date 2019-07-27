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
	ll n,k;
	cin>>n>>k;
	map<ll,ll> mp;
	for (ll i = 0; i < n; i++){
		ll a,b;
		cin>>a>>b;
		mp[a] += b;
	}

	ll cnt = 0;
	for(auto x:mp){
		cnt += x.second;
		if(cnt>=k){
			cout<<x.first<<endl;
			break;
		}
	}
	return 0;
}