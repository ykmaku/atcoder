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
	int a,b;
	cin>>a>>b;

	string grid[100];
	rep(i,100)grid[i].resize(100);
	for (int i = 0; i < 50; i++){
		rep(j,100)grid[i][j]='#';
	}
	for (int i = 50; i < 100; i++){
		rep(j,100) grid[i][j] = '.';
	}
	int cnt = 0;
	for (int i = 0; i < 49; i+=2){
		if(cnt==a-1)break;
		for (int j = (i%2==0?0:1); j < 100; j+=2){
			grid[i][j] = '.';
			cnt++;
			if(cnt==a-1)break;
		}
	}

	cnt=0;
	for (int i = 51; i < 100; i+=2){
		if(cnt==b-1)break;
		for (int j = (i%2==0?0:1); j < 100; j+=2){
			grid[i][j] = '#';
			cnt++;
			if(cnt==b-1)break;
		}
	}
	cout<<100<<" "<<100<<endl;
	rep(i,100){
		cout<<grid[i]<<endl;
	}
	return 0;
}