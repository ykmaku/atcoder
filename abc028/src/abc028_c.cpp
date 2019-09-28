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
	int a[5]={};
	rep(i,5)cin>>a[i];
	vector<int> v;

	for (int i = 0; i < 5; i++){
		for (int j = i+1; j < 5; j++){
			for (int k = j+1; k < 5; k++){
				int x = a[i]+a[j]+a[k];
				v.push_back(x);
			}
		}
	}
	sort(all(v));
	reverse(all(v));
	cout<<v[2]<<endl;
	return 0;
}