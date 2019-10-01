#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i,(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main()
{
	double a,b,c;
	cin>>a>>b>>c;

	double left=0,right=120;
	double res=10;
	double t=0;
	while(abs(res)>1e-15){
		t=(left+right)/2;
		res=a*t+b*sin(c*M_PI*t)-100;;
		if(res<0)left=t;
		else right=t;
	}
	cout<<setprecision(15)<<t<<endl;

	return 0;
}