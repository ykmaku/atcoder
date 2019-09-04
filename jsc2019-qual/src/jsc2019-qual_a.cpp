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
	int m,d;
	cin>>m>>d;
	int ans = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= d; j++){
			int d1 = j%10;
			int d10 = j/10;
			if(d1>=2 && d10>=2 && d1*d10==i){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}