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

bool check(int x1,int x2,int x3){
	return (x1<=x2 && x2<=x3)||(x1>=x2 && x2>=x3);
}

int main()
{
	int n;
	cin>>n;
	vector<int>a(n+2,0);
	for (int i = 1; i < n+1; i++){
		cin>>a[i];
	}
	int sum = 0;
	for (int i = 1; i <= n+1; i++){
		sum += abs(a[i-1]-a[i]);
	}
	for (int i = 1; i < n+1; i++){
		cout<<sum - abs(a[i-1]-a[i]) - abs(a[i]-a[i+1]) + abs(a[i-1]-a[i+1])<<endl;
	}
	
	return 0;
}