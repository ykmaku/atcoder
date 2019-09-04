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
	vector<int> a(3);
	rep(i,3)cin>>a[i];
	int cnt;
	int ans = 0;
	rep(i,3)if(a[i]%2==0)cnt++;
	if(cnt!=0&&cnt!=3){
		ans++;
		rep(i,3){
			if(cnt==1&&a[i]%2!=0)a[i]++;
			if(cnt==2&&a[i]%2==0)a[i]++;
		}
	}
	sort(all(a));
	cout<<ans+(a[2]-a[0]+a[2]-a[1])/2<<endl;
	return 0;
}