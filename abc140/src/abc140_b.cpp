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

#define rep(i,n) for(int i=0;i<(n);++i)
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
	vector<int> a(n),b(n),c(n-1);
	rep(i,n){cin>>a[i];a[i]--;}
	rep(i,n)cin>>b[i];
	rep(i,n-1)cin>>c[i];

	int ans = 0;
	int now = -1;
	rep(i,n){
		if(now>=0 && now+1==a[i]){
			ans += c[now];
		}
		now = a[i];
		ans += b[now];
	}
	cout<<ans<<endl;

	return 0;
}