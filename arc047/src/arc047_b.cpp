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
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	int n;
	cin>>n;
	vector<int> u(n),v(n);
	rep(i,n){
		int x,y;
		cin>>x>>y;
		u[i] = x+y;
		v[i] = x-y;
	}

	int max_u = *max_element(all(u)), min_u = *min_element(all(u));
	int max_v = *max_element(all(v)), min_v = *min_element(all(v));

	int r = max(max_u-min_u,max_v-min_v)/2; 

	vector<P> candidate;
	candidate.push_back(P(min_u+r,min_v+r));
	candidate.push_back(P(min_u+r,max_v-r));
	candidate.push_back(P(max_u-r,min_v+r));
	candidate.push_back(P(max_u-r,max_v-r));

	// cout<<candidate.size()<<endl;
	for(auto p: candidate){
		// if((p.first+p.second)%2!=0 || (p.first-p.second)%2!=0) continue;
		int px = (p.first+p.second)/2;
		int py = (p.first-p.second)/2;

		int dist = -1;
		bool flag = true;
		rep(i,n){
			int x = (u[i]+v[i])/2;
			int y = (u[i]-v[i])/2;
			if(dist<0) dist = abs(px-x)+abs(py-y);
			
			// cout<< dist<<" "<<abs(px-x)+abs(py-y)<<endl;
			if(dist != abs(px-x)+abs(py-y)) flag=false;
		}
		if(flag){
			cout<<px<<" "<<py<<endl;
			return 0;
		}
	}

	
	return 0;
}