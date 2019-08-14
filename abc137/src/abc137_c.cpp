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
	int n;
	cin>>n;
	vector<string> s(n);
	for (int i = 0; i < n; i++){
		cin>>s[i];
	}
	for (int i = 0; i < n; i++){
		sort(all(s[i]));
	}
	sort(all(s));
	// for(auto x : s){
	// 	cout<<x<<endl;
	// }
	ll ans = 0;
	ll cnt = 0;
	for (int i = 1; i < n; i++){
		if(s[i]==s[i-1]){
			if(cnt==0) cnt = 2;
			else cnt++;
		}else{
			ans += cnt*(cnt-1)/2;
			cnt = 0;
		}
	}
	ans += cnt*(cnt-1)/2;
	cout<<ans<<endl;
	
	return 0;
}