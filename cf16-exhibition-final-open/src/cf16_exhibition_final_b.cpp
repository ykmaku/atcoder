#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;

typedef long long int ll;
typedef pair<double,double> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

P vec(P from,P to){
	return P(to.first-from.first,to.second-from.second);
}

double len(P a,P b){
	P v = vec(a,b);
	return sqrt(pow(v.first,2)+pow(v.second,2));
}

double getInradious(P a,P b,P c){
	P v = vec(a,b);
	P u = vec(a,c);

	double area = abs(v.first*u.second - v.second*u.first)/2;
	double l1 = len(a,b), l2 = len(b,c), l3 = len(c,a);

	return 2*area/(l1+l2+l3);
}


int main()
{
	P p[3];
	rep(i,3) cin>>p[i].first>>p[i].second;

	double ans = 0;

	P v01=vec(p[0],p[1]), v02=vec(p[0],p[2]), v12=vec(p[1],p[2]);
	double l01=len(p[0],p[1]), l02=len(p[0],p[2]), l12=len(p[1],p[2]);

	double ratio = l02/(l02+l12);
	P m01 = P(p[0].first+v01.first*ratio, p[0].second+v01.second*ratio);
	ans = max(ans,getInradious(m01,p[0],p[2]));

	ratio = l01/(l01+l12);
	P m02 = P(p[0].first+v02.first*ratio, p[0].second+v02.second*ratio);
	ans = max(ans,getInradious(m02,p[0],p[1]));

	ratio = l01/(l01+l02);
	P m12 = P(p[1].first+v12.first*ratio, p[1].second+v12.second*ratio);
	ans = max(ans,getInradious(m12,p[0],p[1]));


	cout<<setprecision(15) << ans<<endl;


	return 0;
}