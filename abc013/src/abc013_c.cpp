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
	ll n,h,a,b,c,d,e;
	cin >> n >>h>>a>>b>>c>>d>>e;
 
	h -= n*e;
	h *= -1;
	if(h<0){
		cout << 0 << endl;
		return 0;
	}
	ll ans = INF*INF;
	for(int i = 0; i <= n; i++){
		ll res = a*i;
		ll cnt_c = ceil((double)(h-(b+e)*i)/(d+e));
		if(h == (b+e)*i + (d+e)*cnt_c) cnt_c = ceil((double)(h-(b+e)*i+1)/(d+e));
		if(cnt_c > n-i) continue;
		res += max((ll)0,cnt_c) * c;
 
		ans = min(ans,res);
	}
	cout<< ans << endl;
	return 0;
}