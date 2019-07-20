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
typedef pair<ll,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct edge{
	int to;
	ll cost;
	edge(int t,ll c){to=t;cost=c;}
};

vector<P> dijkstra(int root,vector<vector<edge>> g){
	priority_queue<P,vector<P>,greater<P> > que;

	int n = g.size();
	vector<P> dist(n,P(1e18,-1));
	dist[root] = P(0LL,root);
	que.push(P(0LL,root));
	
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second;
		if(dist[v].first < p.first) continue;
	
		for(int i = 0; i < g[v].size(); i++){
			edge e = g[v][i];
			if(dist[v].first +  e.cost < dist[e.to].first){
				dist[e.to].first = dist[v].first + e.cost;
				dist[e.to].second = e.to;
				que.push(P(dist[e.to].first,e.to));
			}
		}
	}
	cout<<endl;
	return dist;
}

vector<ll> num_of_paths(vector<P> dist,vector<vector<edge> > g){
	int n = dist.size();
	vector<ll> num(n,0LL);
	sort(all(dist));

	vector<ll> dist2(n);
	for (int i = 0; i < n; i++)
	{
		dist2[dist[i].second] = dist[i].first;
	}
	 
	num[dist[0].second] = 1LL;
	for(auto v:dist){
		// cout << v.first <<" " <<v.second<< endl;
		int from = v.second;
		ll distance = v.first;
		for(auto x:g[from]){
			// cout << x.to<<" ";
			int to = x.to;
			ll weight = x.cost;
			if(distance + weight == dist2[to]){
				num[to] += num[from];
				num[to] %= mod;
			}
		}
	}
	return num;
}

ll func(ll x,ll y){
	ll ret = 1;
	ret *= x*x;
	ret %= mod;
	ret *= y*y;
	ret %= mod;
	return ret;
}

int main()
{
	int n,m;
	cin>>n>>m;
	int s,t;
	cin>>s>>t;
	s--;t--;
	vector<vector<edge> > g(n,vector<edge>()); 
	for (int i = 0; i < m; i++){
		int u,v;
		ll d;
		cin>>u>>v>>d;
		u--;v--;
		g[u].push_back(edge(v,d));
		g[v].push_back(edge(u,d));
	}
	

	vector<P> dist_s = dijkstra(s,g);
	vector<P> dist_t = dijkstra(t,g);

	assert(dist_s.size()==n);
	assert(dist_t.size()==n);

	vector<ll> num_s = num_of_paths(dist_s,g);
	vector<ll> num_t = num_of_paths(dist_t,g);

	assert(num_s.size()==n);
	assert(num_t.size()==n);
	assert(num_s[t] == num_t[s]);
	

	ll l = dist_s[t].first;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		if(2*dist_s[i].first==l){
			ans += func(num_s[i],num_t[i]);
			ans %= mod;
		}
	}
	for (int i = 0; i < n; i++){
		for(auto x : g[i]){
			int u = i;
			int v = x.to;
			ll cost = x.cost;
			if(2*dist_s[u].first<l && 2*dist_s[v].first>l && dist_s[u].first + cost == dist_s[v].first){
				ans += func(num_s[u],num_t[v]);
				ans %= mod;
			}
		}
	}
	
	
	// cout<<ans<<endl;
	cout<<((num_s[t]*num_s[t])%mod - ans + mod)%mod<<endl;
	return 0;
}