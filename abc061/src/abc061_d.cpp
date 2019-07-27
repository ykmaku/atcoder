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
typedef pair<int,ll> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;


ll bellman_ford(vector<vector<P> > g,int s,int t){
	int n = g.size();
	vector<ll> dist(n,1e18+10);
	dist[s] = 0;
	vector<bool> nega(n,false);
	for (int i = 0; i < n; i++){
		bool update = false;
		for (int j = 0; j < n; j++){
			for (int k = 0; k < g[j].size(); k++){
				int from = j,to = g[j][k].first;
				ll cost = g[j][k].second;
				if(dist[from] + cost < dist[to]){
					dist[to] = dist[from] + cost;
					update = true;
					if(i==n-1) nega[to] = true;
				}
				if(nega[j]) nega[to] = true;
			}
		}
		if(!update){
			break;
		}
		// for(auto x: dist){
		// 	cout<<x<< " ";
		// }cout<<endl;
	}
	return (!nega[t]?dist[t]:1e18+10);
}

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<P> > g(n,vector<P>());
	for (int i = 0; i < m; i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		a--;b--;
		c *= -1;
		g[a].push_back(P(b,c));
	}

	ll ans = bellman_ford(g,0,n-1);
	if(ans==1e18+10) cout<<"inf"<<endl;
	else cout<<ans*(-1)<<endl;
	return 0;
}