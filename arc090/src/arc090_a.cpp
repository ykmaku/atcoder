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
	int a[2][110] = {};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>a[i][j];
		}
	}

	int ans = 0;
	for (int p = 0; p < n; p++)
	{
		int res = 0;
		int r = 0;
		for (int i = 0; i < n; i++)
		{
			res += a[r][i];
			if(i == p){
				res += a[r+1][i];
				r = 1;
			}
		}
		ans = max(ans,res);
	}
	cout<<ans<<endl;
	
	
	return 0;
}