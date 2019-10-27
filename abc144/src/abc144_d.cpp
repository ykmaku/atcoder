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

double f1(double a,double b,double alpha,double x){
	return a*pow(b,2)*tan(M_PI/2-alpha)-2*x;
}

double f2(double a,double alpha,double x){
	return pow(a,3)*tan(alpha)-2*x;
}

int main()
{
	double a,b,x;
	cin>>a>>b>>x;

	if(2*x<=a*a*b){
		// cout<<"lower case"<<endl;
		double low=0,high=M_PI/2;
		while(abs(f1(a,b,high,x))>1e-8){
			double mid=(low+high)/2;
			if(f1(a,b,mid,x)<0)high=mid;
			else low=mid;
		}
		cout<<setprecision(12)<<high*180/M_PI<<endl;
	}else{
		double low=0,high=M_PI/2;
		x=a*a*b-x;
		while(abs(f2(a,low,x))>1e-8){
			double mid=(low+high)/2;
			if(f2(a,mid,x)<0)low=mid;
			else high=mid;
		}
		cout<<setprecision(12)<<low*180/M_PI<<endl;
	}
	return 0;
}