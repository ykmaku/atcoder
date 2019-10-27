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
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}


int main()
{
	ll n,m,l;
	cin>>n>>m>>l;
	vector<vector<P>> g(n);
	rep(i,m){
		ll a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		if(c<=l){
			g[a].push_back(P(b,c));
			g[b].push_back(P(a,c));
		}
	}

	ll q;
	cin>>q;
	vector<ll>s(q),t(q);
	rep(i,q){
		cin>>s[i]>>t[i];
		s[i]--;t[i]--;
	}
	vector<vector<ll>> dist(n,vector<ll>(n,INF));
	rep(i,n)dist[i][i]=0;
	rep(i,n){
		rep(j,g[i].size())dist[i][g[i][j].first] = g[i][j].second;
	}

	rep(k,n){
		rep(i,n){
			rep(j,n){
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}

	vector<vector<ll>> gg(n);
	rep(i,n){
		repi(j,i+1,n){
			if(i==j)continue;
			if(dist[i][j]<=l){
				gg[i].push_back(j);
				gg[j].push_back(i);
			}
		}
	}
	vector<vector<ll>> dist2(n,vector<ll>(n,INF));
	rep(i,n)dist2[i][i]=0;
	rep(i,n){
		rep(j,gg[i].size())dist2[i][gg[i][j]] = 1;
	}

	rep(k,n){
		rep(i,n){
			rep(j,n){
				dist2[i][j] = min(dist2[i][j],dist2[i][k]+dist2[k][j]);
			}
		}
	}

	rep(i,q){
		cout<<(dist2[s[i]][t[i]]==INF?-1:dist2[s[i]][t[i]]-1)<<endl;
	}



	return 0;
}