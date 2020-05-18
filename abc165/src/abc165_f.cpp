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

int n;
vector<int> a,ans,dp,used;
vector<vector<int>> g;

void dfs(int cur){
	used[cur] = 1;
	int pos = lower_bound(all(dp), a[cur]) - dp.begin();
	int ret;
	if(pos==dp.size()){
		ret = -1;
		dp.push_back(a[cur]);
	}else{
		ret = dp[pos];
		dp[pos] = a[cur];
	}

	ans[cur] = dp.size();

	for(auto x:g[cur]){
		if(used[x]==0) dfs(x);
	}

	if(ret==-1){
		dp.pop_back();
	}else{
		dp[pos] = ret;
	}
}


int main()
{
	cin>>n;
	a.resize(n);
	ans.resize(n,1);
	used.resize(n,0);
	rep(i,n) cin>>a[i];
	g.resize(n);
	rep(i,n-1){
		int u, v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0);

	rep(i,n)cout<<ans[i]<<endl;


	return 0;
}