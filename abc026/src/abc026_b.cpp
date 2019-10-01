#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i,(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const double PI = M_PI;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	int n;
	cin>>n;
	vector<double> r(n);
	rep(i,n)cin>>r[i];
	sort(all(r));
	reverse(all(r));
	double ans=0;
	rep(i,n){
		double area=PI*r[i]*r[i];
		if(i%2==0)ans+=area;
		else ans-=area;
	}
	cout<< setprecision(12) <<ans<<endl;
	return 0;
}