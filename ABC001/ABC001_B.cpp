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
	int m;
	cin>>m;
	int vv;
	if(m<100)
		vv=0;
	else if(m<=5000)
		vv=m/100;
	else if(m<=30000)
		vv=m/1000+50;
	else if(m<=70000)
		vv=(m/1000-30)/5+80;
	else
		vv=89;
	printf("%02d\n", vv);

	return 0;
}
