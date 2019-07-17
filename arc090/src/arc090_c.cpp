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
typedef pair<int,ll> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

vector<vector<P>> g,edge;
vector<ll> dist;


ll func(ll x,ll y){
	ll ret = 1;
	ret *= pow(x,2);
	ret %= mod;
	ret *= pow(y,2);
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
	g.resize(n,vector<P>());
	dist.resize(n,1e18);
	edge.resize(n,vector<P>());
	for (int i = 0; i < m; i++)
	{
		int a,b;
		ll d;
		cin>>a>>b>>d;
		a--;b--;
		g[a].push_back(P(b,d));
		g[b].push_back(P(a,d));
		edge[a].push_back(P(b,d));
	}

	vector<ll> num_s(n,0),num_t(n,0);
	auto comp = [](P x,P y){return x.second > y.second;};
	priority_queue<P,vector<P> ,decltype(comp)> q(comp);
	dist[s] = 0;
	q.push(P(s,0));
	while(!q.empty()){
		P p = q.top();
		q.pop();
		if(dist[p.first]<p.second) continue;
		for(auto x : g[p.first]){
			int to = x.first;
			ll cost = x.second;
			if(dist[to] > dist[p.first]+cost){
				// num_s[to] += num_s[p.first];
				// num_s[to] %= mod;
				dist[to] = dist[p.first] + cost;
				q.push(P(to,dist[to]));
			}
		}
	}

	num_s[s] = 1;
	q.push(P(s,0));
	while(!q.empty()){
		P p = q.top();q.pop();
		for(auto x:g[p.first]){
			int to = x.first;
			ll cost = x.second;
			if(dist[to] == dist[p.first] + cost){
				num_s[to] += num_s[p.first];
				num_s[to] %= mod;
				q.push(P(to,dist[to]));
			}
		}
	}

	auto comp2 = [](P x,P y){return x.second < y.second;};
	priority_queue<P,vector<P> ,decltype(comp2)> q2(comp2);
	num_t[t] = 1;
	q2.push(P(t,dist[t]));
	while(!q2.empty()){
		P p = q2.top();q2.pop();
		if(dist[p.first]>p.second) continue;
		for(auto x:g[p.first]){
			int to = x.first;
			ll cost = x.second;
			if(dist[to] == dist[p.first] - cost){
				num_t[to] += num_t[p.first];
				num_t[to] %= mod;
				q2.push(P(to,dist[to]));
			}
		}
	}
	
	ll l = dist[t];
	ll ans = 0;
	for (int i = 0; i < n; i++){
		if(2*dist[i]==l){
			// cout<<"i = "<<i<<endl;
			// cout<<num_s[i] << " " << num_t[i] << endl;
			ans += func(num_s[i],num_t[i]);
			ans %= mod;
			// cout<<"ans = "<<ans<<endl;
		}
	}
	for (int i = 0; i < n; i++){
		for(auto x : edge[i]){
			int u = i;
			int v = x.first;
			ll cost = x.second;
			if(dist[v]<=dist[u]){
				int tmp = u;
				u = v;
				v = tmp;
			}
			if(2*dist[u]<l && 2*dist[v]>l && dist[u] + cost == dist[v]){
				ans += func(num_s[u],num_t[v]);
				ans %= mod;
			}
		}
	}
	cout<<((num_s[t]*num_s[t])%mod - ans + mod)%mod<<endl;
	

	// cout<<"l = "<< l<<endl;
	// cout<<"num_s[t] = "<<num_s[t]<<endl;
	
	
	return 0;
}