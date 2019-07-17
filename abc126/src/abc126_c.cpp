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
	int n,k;
	cin>>n>>k;

	double ans = 0.0;
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		int ret = 1;
		while(i*ret < k){
			cnt++;
			ret*=2;
		}
		ans += pow(0.5,cnt);
	}
	printf("%.15f\n", ans/n);


	return 0;
}
