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
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	ll ans=0;
	rep(i,n){
		if(s[i]=='L' && i>0 && s[i-1]=='L')ans++;
		if(s[i]=='R' && i<n-1 && s[i+1]=='R')ans++;
	}
	cout<<min(n-1,ans+2*k)<<endl;
	return 0;
}