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

double calc(double w1,double w2,double p1,double p2){
	return (w1*p1+w2*p2)/(w1+w2);
}

int main()
{
	int n,k;
	cin>>n>>k;
	vector<P> salt_water(n);
	rep(i,n)cin>>salt_water[i].first>>salt_water[i].second,salt_water[i].second/=100;

	// rep(i,n)cout<<salt_water[i].first<<" ";
	// cout<<endl;

	double low=0,high=1;
	while(abs(high-low)>1e-8){
		double mid=(low+high)/2;
		double weight=0,salt=0;

		sort(all(salt_water),[&](P x1,P x2){
			return x1.first*(x1.second-mid)>x2.first*(x2.second-mid);
		});

		rep(i,min(n,k)){
			weight+=salt_water[i].first;
			salt  +=salt_water[i].first*salt_water[i].second;
		}
		if(salt/weight<mid)high=mid;
		else low=mid;
	}

	cout<<setprecision(9)<<high*100<<endl;


	return 0;
}