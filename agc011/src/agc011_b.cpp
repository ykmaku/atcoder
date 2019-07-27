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
	vector<ll> a(n);
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}
	sort(all(a));
	vector<ll> sum(n+1,0LL);
	for (int i = 0; i < n; i++){
		sum[i+1] = sum[i] + a[i];
	}
	int ans = 1;
	for (int i = 0; i < n-1; i++){
		if(sum[i+1]*2 < a[i+1]) ans = 1;
		else ans++;
	}
	cout<<ans<<endl;
	return 0;
}