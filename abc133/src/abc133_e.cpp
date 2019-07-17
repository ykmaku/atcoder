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

vector<vector<ll> > g;
vector<ll> cnt;

void dfs(int x,ll k){
	ll num=2;
	for(auto p :g[x]){
		if(cnt[p]<0){
			cnt[p] = max(0LL,k-num);
			num++;
			dfs(p,k);
		}
	}
}

int main()
{
	ll n,k;
	cin>>n>>k;
	if(n==1){
		cout<<k<<endl;
		return 0;
	}
	g.resize(n,vector<ll>());
	cnt.resize(n,-1LL);
	for (int i = 0; i < n-1; i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int s = -1;
	for (int i = 0; i < n; i++){
		if(g[i].size()==1){
			s=i;
			break;
		}
	}
	cnt[s] = k;
	cnt[g[s][0]] = k-1;
	dfs(g[s][0],k);

	ll ans = 1;
	for(auto x : cnt){
		ans *= x;
		ans %=mod;
	}
	
	cout<<ans<<endl;
	
	return 0;
}