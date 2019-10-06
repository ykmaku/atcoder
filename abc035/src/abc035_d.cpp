#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9*1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<ll> dijkstra(vector<vector<P>> &g,int r){
	priority_queue<P,vector<P>,greater<P>> que;

	int n = g.size();
	vector<ll> dist(n,INF);
	dist[r]=0;
	que.push(P(dist[r],r));
	while(!que.empty()){
		ll dist_from=que.top().first;
		ll node_from=que.top().second;
		que.pop();

		if(dist[node_from]<dist_from) continue;
		for(P p: g[node_from]){
			ll w=p.second;
			int node_to=p.first;
			if(dist[node_to]>dist_from+w){
				dist[node_to]=dist_from+w;
				que.push(P(dist[node_to],node_to));
			}
		}
	}

	return dist;
}

int main()
{
	int n,m;
	ll t;
	cin>>n>>m>>t;
	vector<ll> a(n);
	rep(i,n)cin>>a[i];
	vector<vector<P>> g(n),rg(n);
	rep(i,m){
		ll a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		g[a].push_back(P(b,c));
		rg[b].push_back(P(a,c));
	}

	vector<ll> dist=dijkstra(g,0);
	vector<ll> dist_r=dijkstra(rg,0);

	rep(i,n)dist[i]+=dist_r[i];

	vector<ll> score(n,0);
	rep(i,n){
		if(t-dist[i]<0)continue;
		score[i]=(t-dist[i])*a[i];
	}
	cout<<*max_element(all(score))<<endl;

	return 0;
}