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


int main()
{
	int h,w;
	cin>>h>>w;
	vector<vector<char>> c(h,vector<char>(w));
	int sx,sy,gx,gy;
	rep(i,h)rep(j,w){
		cin>>c[i][j];
		if(c[i][j]=='s')sx=i,sy=j;
		if(c[i][j]=='g')gx=i,gy=j;
	}

	vector<vector<P>> g(h*w);
	rep(x,h)rep(y,w){
		rep(i,4){
			int nx=x+dx[i],ny=y+dy[i];
			if(valid(0,h,0,w,nx,ny)){
				if(c[nx][ny]!='#'){
					g[x*w+y].push_back(P(0,nx*w+ny));
				}else{
					g[x*w+y].push_back(P(1,nx*w+ny));
				}
			}
		}
	}

	vector<int> dist(h*w,INF);
	dist[sx*w+sy]=0;

	priority_queue<P,vector<P>,greater<P>> que;

	que.push(P(0,sx*w+sy));

	while(!que.empty()){
		P p = que.top();que.pop();	
		for(auto x:g[p.second]){
			if(dist[x.second]>dist[p.second]+x.first){
				dist[x.second]=dist[p.second]+x.first;
				que.push(P(dist[x.second],x.second));
			}
		}
	}

	cout<<(dist[gx*w+gy]<=2?"YES":"NO")<<endl;
	
	return 0;
}