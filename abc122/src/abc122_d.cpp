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
typedef pair<int,string> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n;
map<P,ll> dp;

bool func(string x){
	for (int i = 0; i < x.size(); i++){
		string y = x;
		if(i>0){
			char tmp = y[i];
			y[i] = y[i-1];
			y[i-1] = tmp;
		}
		if(y.find("AGC")!=string::npos) return false;
	}
	return true;
}

ll dfs(P p){
	if(dp.count(p)>0) return dp[p];
	if(p.first==n) return 1;

	ll res = 0;
	string t = "AGCT";
	for (int j = 0; j < 4; j++){
		string x = p.second+t[j];
		if(func(x)){
			string y = p.second.substr(1,2) + t[j];
			res += dfs(P(p.first+1,y));
			res %= mod;
		}
	}
	dp[p] = res;
	return res;
}

int main()
{
	cin>>n;
	cout<<dfs(P(0,"TTT"))<<endl;
	return 0;
}