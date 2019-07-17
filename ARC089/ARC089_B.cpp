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

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int n,k;
vector<vector<int> > sum;
int func(int i,int j){
	return sum[i][j] - sum[i-k][j] -sum[i][j-k] + sum[i-k][j-k];
}

int main()
{
	cin>>n>>k;
	int t = 2*k;
	int f=4*k;
	sum.resize(4*k+5,vector<int>(4*k+5,0));
	for (int i = 0; i < n; i++)
	{
		int x,y;
		string c;
		cin>>x>>y>>c;
		x%=t;
		y%=t;
		if(c=="B") x+=k;
		x%=t;
		sum[x][y]++;
		sum[x+t][y]++;
		sum[x][y+t]++;
		sum[x+t][y+t]++;
	}
	
	for (int i = 1; i < f; i++){
		for (int j = 1; j < f; j++){
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	int ans = 0;
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			int tmp = func(i+k,j+k) + func(i+2*k,j+2*k);
			ans = max(ans,tmp);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}