#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

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
int h,w;

int bfs(int sh,int sw,vector<string> g){
	vector<vector<int>> dist(h,vector<int>(w,INF));
	queue<P> que;
	que.push(P(sh,sw));

	dist[sh][sw] = 0;
	while(!que.empty()){
		P p = que.front();que.pop();
		int x = p.first, y = p.second;
		rep(i,4){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(valid(0,h,0,w,nx,ny) && g[nx][ny] != '#'){
				if(dist[nx][ny]==INF){
					dist[nx][ny] = dist[x][y] + 1;
					que.push(P(nx,ny));
				}
			}
		}
	}

	int ret = 0;
	rep(i,h)rep(j,w){
		if(dist[i][j] < INF) ret = max(ret,dist[i][j]);
	}
	return ret;
}

int main()
{
	cin>>h>>w;
	vector<string> s(h);
	rep(i,h)cin>>s[i];

	int ans = 0;

	rep(sh,h){
		rep(sw,w){
			if(s[sh][sw]=='#')continue;
			ans = max(ans,bfs(sh,sw,s));
		}
	}
	cout<<ans<<endl;

	return 0;
}