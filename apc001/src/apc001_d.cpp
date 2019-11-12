#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll,int> P;

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

void dfs(int r,vector<vector<int>> &g,vector<int> &comp,int cnt){
	comp[r]=cnt;
	for(auto x:g[r]){
		if(comp[x]<0)dfs(x,g,comp,cnt);
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<ll> a(n);
	rep(i,n)cin>>a[i];
	vector<vector<int>> g(n,vector<int>());
	rep(i,m){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(m==n-1){
		cout<<0<<endl;
		return 0;
	}
	vector<int> comp(n,-1);
	int cnt=0;
	rep(i,n){
		if(comp[i]<0){
			dfs(i,g,comp,cnt);
			cnt++;
		}
	}
	// cnt=n-m;
	// cout<<"cnt = "<<cnt<<endl;

	if(2*(cnt-1)>n){
		cout<<"Impossible"<<endl;
		return 0;
	}

	vector<multiset<ll>> s(cnt);
	rep(i,n){
		s[comp[i]].emplace(a[i]);
	}
	priority_queue<ll,vector<ll>,greater<ll>> que;

	ll ans=0;
	int num=0;
	rep(i,cnt){
		ans+=*s[i].begin();
		// s[i].erase(*s[i].begin());
		num++;
	}
	rep(i,cnt){
		auto itr = s[i].begin();
		itr++;
		for(; itr!=s[i].end(); ++itr)que.push(*itr);
	}
	while(num<2*(cnt-1)){
		ans+=que.top();que.pop();
		num++;
	}
	cout<<ans<<endl;

	
	return 0;
}