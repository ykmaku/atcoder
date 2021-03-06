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

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n);
	rep(i,n)cin>>a[i];

	priority_queue<ll> que;
	rep(i,n)que.push(a[i]);

	while(m--){
		ll p = que.top();que.pop();
		p /= 2;
		que.push(p);
	}
	ll ans = 0;
	while(!que.empty()){
		ll p = que.top();que.pop();
		ans += p;
	}
	cout<<ans<<endl;
	return 0;
}