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
	string s;
	cin>>s;
	int n = s.length();
	vector<int> l(n),r(n);
	int cnt = 0;
	vector<int> ans(n);
	for (int i = 0; i < n; i++){
		if(s[i]=='R') cnt++;
		else{
			l[i] = cnt;
			ans[i] += cnt/2;
			ans[i-1] += cnt/2 + cnt%2;
			cnt = 0;
		}
	}
	cnt = 0;
	for (int i = n-1; i >= 0; i--){
		if(s[i]=='L') cnt++;
		else{
			r[i] = cnt;
			ans[i] += cnt/2;
			ans[i+1] += cnt/2 + cnt%2;
			cnt = 0;
		}
	}

	for(auto x : ans) cout<<x<<" ";
	cout<<endl;
	return 0;
}