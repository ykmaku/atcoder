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
	int n,m;
	cin>>n>>m;
	vector<int> cnt(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--;b--;
		cnt[a]++;
		cnt[b]++;
	}
	bool flag = true;
	rep(i,n)if(cnt[i]%2!=0)flag=false;
	cout<<(flag?"YES":"NO")<<endl;
	return 0;
}