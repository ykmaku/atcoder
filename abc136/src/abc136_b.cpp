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

int f(int x){
	int res = x;
	int cnt = 0;
	while(res>0){
		res /= 10;
		cnt++;
	}
	return cnt;
}

int main()
{
	int n;
	cin>>n;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if(f(i)%2==1) ans++;
	}
	cout<<ans<<endl;
	return 0;
}