#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i,(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const double eps=1e-10;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct point{
	int x,y;
	point(int xx,int yy): x(xx),y(yy){};
};

int main()
{
	ll n;
	cin>>n;
	vector<point> p(n,point(0,0));
	rep(i,n)cin>>p[i].x>>p[i].y;

	ll total=n*(n-1)*(n-2)/6;
	ll cnt90=0,cnt=0;

	rep(i,n){
		vector<double> target;
		rep(j,n){
			if(j==i)continue;
			target.push_back(atan2(p[j].y-p[i].y,p[j].x-p[i].x));
		}
		for(auto rad:target)target.push_back(rad+M_PI*2);
		sort(all(target));
		
		rep(j,n-1){
			cnt90 += upper_bound(all(target),target[j]+M_PI/2+eps)-lower_bound(all(target),target[j]+M_PI/2-eps);
			cnt   += lower_bound(all(target),target[j]+M_PI-eps)-upper_bound(all(target),target[j]+M_PI/2+eps);
		}
	}
	cout<<total-cnt-cnt90<<" "<<cnt90<<" "<<cnt<<endl;


	return 0;
}