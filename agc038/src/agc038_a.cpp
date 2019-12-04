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
#define repi(i,a,b)for(int i=a;i<b;++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	int h,w,a,b;
	cin>>h>>w>>a>>b;
	vector<vector<int>> ans(h,vector<int>(w,0));

	if(h==1){
		rep(i,a)ans[0][i]=1;
	}else if(w==1){
		rep(i,b)ans[i][0]=1;
	}else{
		rep(i,b)rep(j,a)ans[i][j]=1;
		repi(i,b,h)repi(j,a,w)ans[i][j]=1;
	}
	rep(i,h){
		rep(j,w)cout<<ans[i][j];
		cout<<endl;
	}
	return 0;
}