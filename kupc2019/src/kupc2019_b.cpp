#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}

struct union_find{
  vector<int> par,r,w,v;

  union_find(ll n,vector<ll> &ww,vector<ll> &vv) : par(n),r(n),w(n),v(n){init(n,ww,vv);}

  void init(ll n,vector<ll> ww,vector<ll> vv){
    for(int i = 0; i < n; i++) par[i] = i;
    for(int i = 0; i < n; i++) r[i] = 0,w[i]=ww[i],v[i]=vv[i];
  }

  int find(int x){
    if(par[x] == x) return x;
    else return find(par[x]);
  }

  void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(r[x] < r[y]){
      par[x] = y;
	  v[y]+=v[x];
	  w[y]+=w[x];
    }else{
      par[y] = x;
	  v[x]+=v[y];
	  w[x]+=w[y];
      if(r[x] == r[y]) r[x]++;
    }
  }

  bool same(int x,int y){
    return find(x) == find(y);
  }
};

int main()
{
	ll n,m,W;
	cin>>n>>m>>W;
	vector<ll> w(n),v(n);
	rep(i,n)cin>>w[i]>>v[i];
	vector<int> a(m),b(m);
	rep(i,m) cin>>a[i]>>b[i],a[i]--,b[i]--;

	union_find uf(n,w,v);
	rep(i,m){
		if(!uf.same(a[i],b[i])) uf.unite(a[i],b[i]);
	}
	vector<P> item;
	rep(i,n){
		if(uf.par[i]==i) item.push_back(P(uf.w[i],uf.v[i]));
	}
	n = item.size();
	vector<vector<ll>> dp(n+1,vector<ll>(W+1,0));


	for (int i = n-1; i >=0; i--){
		rep(j,W+1){
			if(j<item[i].first) dp[i][j] = dp[i+1][j];
			else dp[i][j] = max(dp[i+1][j],dp[i+1][j-item[i].first]+item[i].second);
		}
	}

	cout<<dp[0][W]<<endl;
	return 0;
}