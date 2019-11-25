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

void dfs(int r,vector<vector<int>> &g, map<P,P> &edge,int c,int k,int n,vector<int> &used){
	used[r]=1;
	int color = 1;
	if(color==c)color++;
	for(auto x:g[r]){
		if(used[x]>0)continue;
		int min_ = min(r,x);
		int max_ = max(r,x);
		edge[P(min_,max_)].second = color;
		dfs(x,g,edge,color,k,n,used);
		color++;
		if(color==c)color++;
	}
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int>> g(n,vector<int>());
	map<P,P> edge;
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);

		if(a>b){
			int tmp=a;
			a=b;
			b=tmp;
		}
		edge.insert(make_pair(P(a,b),P(i,0)));
	}

	vector<int> deg(n);
	rep(i,n)deg[i] = g[i].size();
	int color = *max_element(all(deg));
	int r=-1;
	rep(i,n)if(deg[i]==g[i].size()){
		r=i;
		break;
	}
	vector<int> used(n,0);
	dfs(r,g,edge,0,color,n,used);
	
	vector<P> ans;
	for(auto x:edge){
		ans.push_back(x.second);
	}

	sort(all(ans));

	cout<<color<<endl;
	rep(i,n-1){
		cout<<ans[i].second<<endl;
	}


	return 0;
}