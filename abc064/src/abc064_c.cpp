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
	int n;
	cin>>n;
	vector<int> a(n),cnt(9);
	for (int i = 0; i < n; i++){
		cin>>a[i];
		a[i]/=400;
		if(a[i]>8) a[i] = 8;
		cnt[a[i]]++;
	}
	int num = 0;
	for (int i = 0; i < 8; i++){
		if(cnt[i]>0) num++;
	}
	cout<<(num>0?num:1)<< " "<<num+cnt[8]<<endl;
	
	return 0;
}