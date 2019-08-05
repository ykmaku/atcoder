#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int a[MAXN],w[MAXN],rec[MAXN][MAXW+1];

int brute_force(int i,int j){
	int res = 0;
	if (i == n){
		res = 0;
	}else if (j < a[i]){
		res = rec(i+1,j);
	}else{
		res = max(rec(i+1,j),rec(i+1,j-a[i])+w[i]);
	}

	return res;
}

void dp(){
	for(int i = n-1; i >= 0; i--){
		for(int i = 0; i <= W; i++){
			if(j < w[i]){
				dp[i][j] = dp[i+1][j];
			}else{
				dp[i][j] = max(dp[i+1][j],dp[i+1][j-a[i]]+w[i]);
			}
		}
	}

	cout << dp[0][W] << endl;
}

int main()
{
	

	return 0;
}