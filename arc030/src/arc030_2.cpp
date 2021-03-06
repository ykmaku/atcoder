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

bool dfs(int r,vector<vector<int>> &g, vector<int> &used, vector<int> &togo,vector<int> &h){
	used[r]=1;
	if(h[r]==1)togo[r]=1;
	for(auto x:g[r]){
		if(used[x]<0&&dfs(x,g,used,togo,h)){
			togo[r]=1;
		}
	}
	return togo[r]>0;
}

int main()
{
	int n,x;
	cin>>n>>x;
	x--;
	vector<int> h(n);
	rep(i,n)cin>>h[i];
	vector<vector<int>> g(n,vector<int>());
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> used(n,-1),depth(n,0),togo(n,0);

	dfs(x,g,used,togo,h);
	int num=accumulate(all(togo),0);
	if(num==0)num=1;

	cout<<2*(num-1)<<endl;

	return 0;
}