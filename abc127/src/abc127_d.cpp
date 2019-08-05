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
typedef pair<ll,int> P;

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
	vector<ll> a(n);
	vector<P> p(m);
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}
	for (int i = 0; i < m; i++){
		cin>>p[i].second>>p[i].first;
	}

	sort(all(a));
	sort(all(p));
	reverse(all(p));

	int pos = 0;
	for (int i = 0; i < m; i++){
		int cnt = 0;
		while(a[pos]<p[i].first && cnt<p[i].second){
			a[pos] = p[i].first;
			cnt++;
			pos++;
		}
	}
	cout<<accumulate(all(a),0LL)<<endl;
	return 0;
}