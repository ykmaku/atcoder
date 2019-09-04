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
typedef pair<float,float> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int dist(P p1,P p2){
	return sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
}

int main()
{
	float sx,sy,gx,gy,t,v;
	cin>>sx>>sy>>gx>>gy>>t>>v;
	int n;
	P s=P(sx,sy),g=P(gx,gy);
	vector<P> p(n);
	rep(i,n)cin>>p[i].first>>p[i].second;

	bool flag = false;
	rep(i,n){
		if(dist(s,p[i])+dist(p[i],g)<=v*t) flag=true;
	}
	cout<<(flag?"YES":"NO")<<endl;
	return 0;
}