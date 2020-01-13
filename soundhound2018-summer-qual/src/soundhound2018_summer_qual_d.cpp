#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e16;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

int main()
{
	ll n,m,s,t;
	cin>>n>>m>>s>>t;
	s--;t--;
	vector<vector<P>> g_yen(n,vector<P>()),g_snuuk(n,vector<P>());
	rep(i,m){
		ll u,v,a,b;
		cin>>u>>v>>a>>b;
		u--;v--;
		g_yen[u].push_back(P(v,a));
		g_yen[v].push_back(P(u,a));
		g_snuuk[u].push_back(P(v,b));
		g_snuuk[v].push_back(P(u,b));
	}

	vector<ll> dist_yen(n,INF),dist_snuuk(n,INF);
	priority_queue<P,vector<P>,greater<P>> que;
	que.push(P(0,s));
	dist_yen[s] = 0;
	while(!que.empty()){
		P now = que.top();
		que.pop();
		ll node = now.second;
		ll d = now.first;
		for(auto x : g_yen[node]){
			ll next_node = x.first, next_dist = x.second;
			if(d + next_dist < dist_yen[next_node]){
				dist_yen[next_node] = d + next_dist;
				que.push(P(dist_yen[next_node], next_node));
			}
		}
	}

	que.push(P(0,t));
	dist_snuuk[t] = 0;
	while(!que.empty()){
		P now = que.top();
		que.pop();
		ll node = now.second;
		ll d = now.first;
		for(auto x : g_snuuk[node]){
			ll next_node = x.first, next_dist = x.second;
			if(d + next_dist < dist_snuuk[next_node]){
				dist_snuuk[next_node] = d + next_dist;
				que.push(P(dist_snuuk[next_node], next_node));
			}
		}
	}

	vector<ll> dist(n);
	rep(i,n){
		dist[i] = 1e15 - (dist_yen[i] + dist_snuuk[i]);
	}

	set<P> st;
	rep(i,n){
		st.insert(P(-dist[i],i));
	}

	rep(i,n){
		cout<<(*st.begin()).first*(-1)<<endl;
		// cout<<(*st.begin()).second<<endl;
		st.erase(P(-dist[i],i));
	}
	

	return 0;
}