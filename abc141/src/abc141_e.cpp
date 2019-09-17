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
const int INF = 5*1e3+10;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int solve(string s){
	int n = s.size();
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	int ans=0;
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			if (s[i-1] == s[j-1] &&  i+dp[i-1][j-1] < j ) { 
                dp[i][j] = dp[i-1][j-1] + 1; 
                if (dp[i][j] > ans) { 
                    ans = dp[i][j]; 
                } 
            }else dp[i][j] = 0; 
		}
	}
	return ans;
}

int main()
{
	int n;
	string s;
	cin>>n>>s;
	cout<<solve(s)<<endl;

	return 0;
}