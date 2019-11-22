#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<double,double> P;

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

double dist(P p,P q){
	return sqrt(pow(p.first-q.first,2)+pow(p.second-q.second,2));
}

int main()
{
	int n;
	cin>>n;
	vector<P> p(n);
	rep(i,n){
		cin>>p[i].first>>p[i].second;
	}
	sort(all(p));
	double ans=0;
	do{
		double res=0;
		rep(i,n-1){
			res += dist(p[i+1],p[i]);
		}
		ans += res;
		// cout<<res<<endl;
	}while(next_permutation(all(p)));
	double res=1;
	repi(i,1,n+1) res *= i;


	cout<<setprecision(12)<<ans/res<<endl;
	return 0;
}