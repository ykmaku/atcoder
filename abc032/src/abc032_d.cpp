#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e18;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll knapsack1(vector<ll> &v,vector<ll> &w,ll W){
	int n=v.size();
	vector<vector<ll>> dp(n+1,vector<ll>(W+1,0));
	for(int i=n-1;i>=0;i--){
		rep(j,W+1){
			if(w[i]>j) dp[i][j]=dp[i+1][j];
			else dp[i][j] = max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
		}
	}

	return dp[0][W];
}

ll knapsack2(vector<ll> &v,vector<ll> &w,ll W){
	int n=v.size();
	ll max_v=*max_element(all(v));
	vector<vector<ll>> dp(n+1,vector<ll>(n*max_v+1,INF));
	dp[0][0]=0;
	rep(i,n){
		rep(j,n*max_v+1){
			if(v[i]>j) dp[i+1][j]=dp[i][j];
			else dp[i+1][j] = min(dp[i][j],dp[i][j-v[i]]+w[i]);
		}
	}
	ll ret=0;
	rep(i,n*max_v+1)if(dp[n][i]<=W)ret=i;
	return ret;
}

ll knapsack3(vector<ll> &v,vector<ll> &w,ll W){
	int n = v.size();

	int n2 = n/2;
	vector<P> ps,ps2;

	rep(i,1<<n2){
		ll sv=0,sw=0;
		rep(j,n2){
			if(i>>j&1)sv+=v[j],sw+=w[j];
		}
		ps.push_back(P(sw,sv));
	}
	sort(all(ps));
	ll now=-1;
	rep(i,1<<n2){
		if(now<=ps[i].second) ps2.push_back(ps[i]),now=ps[i].second;
	}

	ll ret =0;
	rep(i,1<<(n-n2)){
		ll sv=0,sw=0;
		rep(j,n-n2){
			if(i>>j&1)sv+=v[n2+j],sw+=w[n2+j];
		}

		if(sw<=W){
			ll t = (lower_bound(all(ps2),P(W-sw,INF))-1)->second;
			ret = max(ret,sv+t);
		}
	}

	return ret;
}

int main()
{
	int n;
	ll W;
	cin>>n>>W;
	vector<ll> v(n),w(n);
	rep(i,n)cin>>v[i]>>w[i];

	ll ans=0;
	if(*max_element(all(w))<=1000){
		ans=knapsack1(v,w,min(W,accumulate(all(w),0LL)));
	}else if(*max_element(all(v))<=1000){
		ans=knapsack2(v,w,W);
	}else{
		ans=knapsack3(v,w,W);
	}
	cout<<ans<<endl;
	return 0;
}