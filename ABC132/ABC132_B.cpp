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
	int n;
	cin>>n;
	vector<int> p(n);
	for(int i = 0; i < n; i++){
		cin>>p[i];
	}
	int ans = 0;
	for(int i = 1; i < n-1; i++){
		if(min({p[i-1],p[i],p[i+1]}) == p[i-1] && max({p[i-1],p[i],p[i+1]})==p[i+1]) ans++;
		if(min({p[i-1],p[i],p[i+1]}) == p[i+1] && max({p[i-1],p[i],p[i+1]})==p[i-1]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}