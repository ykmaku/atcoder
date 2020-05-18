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

int n,m;
vector<int> h, adj_val;
vector<vector<int>> g;


int main()
{
	cin>>n>>m;
	g.resize(n);
	h.resize(n);
	adj_val.resize(n,0);
	rep(i,n)cin>>h[i];
	rep(i,m){
		int a,b;
		cin>>a>>b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);

		adj_val[a-1] = max(adj_val[a-1],h[b-1]);
		adj_val[b-1] = max(adj_val[b-1],h[a-1]);
	}
	int ans=0;
	rep(i,n){
		if(adj_val[i]<h[i])ans++;
	}
	cout<<ans<<endl;
	return 0;
}