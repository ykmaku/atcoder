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
	ll n,c,k;
	cin>>n>>c>>k;
	vector<ll> t(n);
	for (int i = 0; i < n; i++){
		cin>>t[i];
	}
	sort(all(t));
	ll start = t[0];
	int ans = 0;
	int num = 0;
	for (int i = 0; i < n; i++){
		if(num<c && t[i] <= start + k) num++;
		else{
			ans++;
			start = t[i];
			num = 1;
		}
	}
	cout<<ans+1<<endl;
	return 0;
}