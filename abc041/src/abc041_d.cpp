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
#include <bitset>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

int main()
{
	int n,m;
	cin>>n>>m;
	vector<P> edge(m);
	rep(i,m){
		cin>>edge[i].first>>edge[i].second;
		edge[i].first--;
		edge[i].second--;
	}

	vector<ll> dp((1<<(n)));
	dp[0] = 1;
	rep(s,(1<<(n))){
		set<int> candidate;
		rep(i,n){
			if(((1<<i)&s)==0) candidate.insert(i);
			// ((1<<i)&s)==0 bit演算をしてからイコール判定
			// (1<<i)&s==0 イコール判定をしてからbit演算
		}
		for(auto e:edge){
			if(((1<<e.second)&s)>0) candidate.erase(e.first);
		}
		for(auto x: candidate){
			dp[(s|(1<<x))] += dp[s];
		}
			
	}
	cout<<dp[(1<<(n))-1]<<endl;
	return 0;
}