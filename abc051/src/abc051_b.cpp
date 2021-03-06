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
	int k,s;
	cin>>k>>s;
	int ans = 0;
	for (int x = 0; x <= k; x++){
		for (int y = 0; y <= k; y++){
			if(0<= s-(x+y) && s-(x+y) <= k) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}