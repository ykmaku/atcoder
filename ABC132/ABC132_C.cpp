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
	vector<int> d(n);
	for(int i = 0; i < n; i++){
		cin>>d[i];
	}
	sort(all(d));
	cout<<d[n/2] - d[n/2-1]<<endl;
	return 0;
}