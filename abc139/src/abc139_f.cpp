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

double calc(double x,double y,double dx,double dy){
	return sqrt(pow(x+dx,2)+pow(y+dy,2));
}

int main()
{
	int n;
	cin>>n;
	vector<vector<P> > p(8);
	rep(i,n){
		double x,y;
		cin>>x>>y;
		if(x>0&&y>0) p[0].push_back(P(x,y));
		else if(x>0&&y<0) p[1].push_back(P(x,y));
		else if(x<0&&y>0) p[2].push_back(P(x,y));
		else if((x<0&&y<0)) p[3].push_back(P(x,y));
		else if(x>0&&y==0) p[4].push_back(P(x,y));
		else if(x<0&&y==0) p[4].push_back(P(x,y));
		else if(x==0&&y>0) p[4].push_back(P(x,y));
		else if(x==0&&y<0) p[4].push_back(P(x,y));
	}

	double ans = 0;
	rep(i,8){
		double x=0,y=0;
		for(auto q:p[i]){
			x+=q.first;
			y+=q.second;
		}
		double res = calc(x,y,0,0);
		rep(j,8){
			if(j!=i){
				for(auto q:p[j])
				if(res < calc(x,y,q.first,q.second)){
					res = calc(x,y,q.first,q.second);
					x += q.first;
					y += q.second;
				}
			}
		}
		ans = max(ans,res);
	}
	printf("%.26f\n",ans);

	return 0;
}