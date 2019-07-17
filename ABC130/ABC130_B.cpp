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

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int n,x;
	cin>>n>>x;
	vector<int> l(n);
	for (int i = 0; i < n; i++){
		cin>>l[i];
	}
	vector<int> sum(n+1,0);
	int ans = 0;
	for ( int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + l[i-1];
	}
	for (int i = 0; i <= n; i++){
		if(sum[i]<=x) ans++;
	}
	cout<<ans<<endl;
	return 0;
}