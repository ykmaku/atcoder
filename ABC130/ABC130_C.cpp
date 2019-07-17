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
	ll w,h,x,y;
	cin>>w>>h>>x>>y;
	double area = (double)w*h/2;
	cout<<area << " "<< ((w%2==0&&h%2==0&&w/2==x&&h/2==y)?1:0)<<endl;
	return 0;
}