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
	int q;
	cin>>q;
	vector<ll> A(q),B(q);
	rep(i,q)cin>>A[i]>>B[i];
	rep(i,q){
		ll a=A[i];
		ll b=B[i];
		if(a>b){
			ll tmp = b;
			b=a;
			a=tmp;
		}
		ll ans = 0;

		if(a==b || a+1==b) ans=2*a-2;
		else{
			ll c = floor(sqrt(a*b));
			if(c*c==a*b)c--;
			if(c*(c+1)>=a*b) ans = 2*c-2;
			else ans = 2*c-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}