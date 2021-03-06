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

double func(double x, double p){
	return x + p/pow(2,x/1.5);
}

int main()
{
	double p;
	cin>>p;

	double right=p,left=0;
	while(abs(right-left)>1e-9){
		double midl=(right+2*left)/3;
		double midr=(2*right+left)/3;
		if(func(midl,p)<func(midr,p))right=midr;
		else left=midl;
	}
	cout<<setprecision(12)<<func(right,p)<<endl;
	return 0;
}