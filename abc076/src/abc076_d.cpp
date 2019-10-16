#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

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

double f(double l,double r,double v,double x){
	if(x<=l) return v+(l-x);
	if(l<x&&x<=r)return v;
	return v+r+x;
}

int main()
{
	int n;
	cin>>n;
	vector<double> t(n+1,0),v(n);
	repi(i,1,n+1)cin>>t[i];
	rep(i,n)cin>>v[i];

	rep(i,n)t[i+1]+=t[i];
	int T=t[n];

	vector<double> speed(2*T+1,0);
	
	double time=0.5;
	repi(i,1,2*T){
		speed[i]=speed[i-1]+0.5;
		rep(j,n){
			speed[i]=min(speed[i],f(t[j],t[j+1],v[j],time));
		}
		time+=0.5;
	}
	time=T-0.5;
	for(int i = 2*T-1; i >0; i--){
		rep(j,n){
			speed[i]=min(speed[i],speed[i+1]+0.5);
		}
		time-=0.5;
	}
	
	// for(auto s:speed)cout<<s<<" ";
	// cout<<endl;

	double ans=0;
	rep(i,2*T){
		ans += 0.25*(speed[i]+speed[i+1]);
	}
	cout<<setprecision(10)<<ans<<endl;

	return 0;
}