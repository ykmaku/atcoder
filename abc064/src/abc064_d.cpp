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
	string s;
	cin>>n>>s;
	int left = 0,right = 0;
	string ans=s;
	for (int i = 0; i < n; i++){
		if(s[i] == ')'){
			// cout<<s[i]<<endl;
			if(left>0) left--;
			else ans = '('+ans;
		}else{
			left++;
		}
		// cout<< i << s <<left<< endl;
	}

	for (int l = 0; l < left; l++){
		ans += ')';
	}
	cout<<ans<<endl;
	return 0;
}