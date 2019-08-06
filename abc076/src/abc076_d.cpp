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
	// vector<int>t(n);
	vector<double> t(n+1,0),v(n+1,0);
	for (int i = 1; i <= n; i++){
		cin>>t[i];
		// t[i] *= 2;
	}
	for (int i = 1; i <= n; i++){
		cin>>v[i];
		// v[i]*=2;
	}

	vector<double> p(2*(n+1),0);
	for (int i = 0; i < n; i++){
		if(v[i]-v[i+1] >= t[i+1]-t[i]){
			p[i+1] = (v[i]+v[i+1])/2;
			p[i+2] = v[i+1];
		}else{
			double a = v[i]-t[i];
			double b = t[i+1] + v[i+1];
			p[i+1] = (b-a)/2;
			p[i+2] = v[i+1];
		}
	}
	double ans = 0;
	for (int i = 0; i < 2*n; i++){
		ans += 0.25*(p[i]+p[i+1]);
	}
	for(auto pp:p)cout<<pp<<" ";
	cout<<endl;
	cout<<ans<<endl;
	return 0;
}