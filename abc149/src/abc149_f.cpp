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

ll calc(ll x){
	ll ret = power(2,x);
	ret = power(ret,mod-2);
	return ret;
}

vector<vector<int>> dg;
vector<ll> cnt;

ll dfs(vector<vector<int>> &g, vector<int> &used,int x){
	ll total=0;
	used[x] = 1;
	for(auto node:g[x]){
		if(used[node]<0){
			dg[x].push_back(node);
			total += dfs(g,used,node);
		}
	}
	cnt[x] = total+1;
	return total+1;
}

int main()
{
	ll n;
	cin>>n;
	vector<vector<int>> g(n,vector<int>());
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dg.resize(n);
	cnt.resize(n);
	vector<int> used(n,-1);

	int root = -1;
	rep(i,n){
		if(g[i].size()==1){
			dfs(g,used,i);
			root = i;
			break;
		}
	}

	ll ans = 0LL;
	
	rep(i,n){
		if(dg[i].size()==0 || i ==root)continue;
		vector<ll> value;
		for(auto node:dg[i]){
			value.push_back(cnt[node]);
		}
		value.push_back(n-cnt[i]);

		ll res = calc(n-1);

		for(auto x:value){
			ll tmp = calc(n-1-x);
			tmp *= calc(x);
			tmp %= mod;
			tmp *= (power(2,x)-1+mod)%mod;
			tmp %= mod;
			
			res += tmp;
			res %= mod;
		}
			ans += (1 - res+mod)%mod;
			ans %= mod;
			ans *= power(2LL,mod-2);
			ans %= mod;

	}
	cout<<(ans)%mod<<endl;


	return 0;
}