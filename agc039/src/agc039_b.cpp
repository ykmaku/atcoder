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
int bfs(int s,vector<vector<int>> &g,int &n){
	vector<int> dist(n,-1);
	queue<int> que;
	dist[s]=0;
	que.push(s);

	while(!que.empty()){
		int p=que.front();que.pop();
		for(auto x:g[p]){
			if(dist[x]>=0)continue;
			dist[x]=dist[p]+1;
			que.push(x);
		}
	}
	return *max_element(all(dist))+1;
}

bool Bipartite(vector<vector<int>> &g,int &n){
	vector<int> color(n,0);
	color[0]=1;
	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int p=que.front();que.pop();
		for(auto x:g[p]){
			if(color[x]==0){
				color[x]=color[p]*-1;
				que.push(x);
			}else if(color[x]==color[p]) return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int>> g(n);
	vector<string> s(n);
	rep(i,n)cin>>s[i];
	rep(i,n){
		rep(j,n){
			if(s[i][j]=='1')g[i].push_back(j);
		}
	}

	int ans=0;
	rep(i,n){
		ans=max(ans,bfs(i,g,n));
	}

	cout<<(Bipartite(g,n)?ans:-1)<<endl;

	return 0;
}