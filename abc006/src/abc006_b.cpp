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

vector<ll> a;

ll f(int x){
	if(a[x]>=0) return a[x];
	else return a[x] = (f(x-1)+f(x-2)+f(x-3))%10007;
}

int main()
{
	int n;
	cin>>n;
	a.resize(n,-1LL);
	a[0] = 0,a[1] = 0,a[2] = 1;
	cout<<f(n-1)<<endl;
	return 0;
}