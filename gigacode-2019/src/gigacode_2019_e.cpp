#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;
typedef tuple<double,double,double> car;

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

int main()
{	
	int N;
	double L;
	cin>>N>>L;
	double v,d;
	cin>>v>>d;
	vector<car> newcar;
	newcar.push_back(car(0,v,d));
	rep(i,N){
		double x,vv,dd;
		cin>>x>>vv>>dd;
		newcar.push_back(car(x,vv,dd));
	}
	newcar.push_back(car(L,1,0));

	sort(all(newcar));

	vector<double> dp(N+2,0);

	rep(i,N+2){
		if(i==0)continue;
		dp[i] = DBL_MAX;
		rep(j,i){
			double xi = get<0>(newcar[i]);
			double xj = get<0>(newcar[j]);
			double dj = get<2>(newcar[j]);
			double vj = get<1>(newcar[j]);
			if(xi-xj>dj)continue;

			dp[i] = min(dp[i],dp[j]+(xi-xj)/vj);
		}
	}

	if(dp[N+1]==DBL_MAX)cout<<"impossible"<<endl;
	else printf("%.12f\n",dp[N+1]);


	return 0;
}