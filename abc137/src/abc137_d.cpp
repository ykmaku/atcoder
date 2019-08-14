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
typedef pair<int,ll> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	int n,m;
	cin>>n>>m;
	vector<P> job(n);
	for (int i = 0; i < n; i++){
		cin>>job[i].first >> job[i].second;
	}
	priority_queue<ll> que;
	sort(all(job));
	int day = 1;
	int pos = 0;
	ll ans = 0;
	while(day<=m){
		while(job[pos].first<= day && pos<n) que.push(job[pos].second), pos++;
		day++;
		if(que.empty()) continue;
		ans += que.top();
		que.pop();
	}
	cout<<ans<<endl;
	return 0;
}