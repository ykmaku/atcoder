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

double calc(int target,vector<vector<int>> &g){
	int n=g.size();
	vector<double> dp(n,0);
	dp[n-1]=0;
	repr(i,n-2,0){
		double sum=0;
		double max_=0;

		for(auto x:g[i]){
			sum+=dp[x];
			max_=max(max_,dp[x]);
		}

		double size=g[i].size();
		if(i==target){
			sum-=max_;
			size--;
		}

		dp[i]=sum/size+1;
	}

	return dp[0];
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n,vector<int>());

	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--,b--;
		g[a].push_back(b);
	}

	double ans=INF;


	rep(i,n){
		ans=min(ans,calc(i,g));
	}
	cout<<setprecision(10)<<ans<<endl;

	return 0;
}