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
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	vector<P> query(q);
	for (int i = 0; i < q; i++){
		cin>>query[i].first>>query[i].second;
		// query[i].first--;
		// query[i].second--;
	}
	vector<int> sum(n+1,0);
	for (int i = 1; i < n; i++){
		if(s[i]=='C' && s[i-1]=='A') sum[i+1] = 1;
	}
	for (int i = 1; i <= n; i++){
		sum[i] += sum[i-1];
	}
	for(auto qq: query){
		cout<<sum[qq.second] - sum[qq.first]<<endl;
	}
	return 0;
}