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
	string s;
	cin>>s;
	int ans = 0;
	int n = s.size();
	set<char> g = {'A','C','G','T'};
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			for (int k = i; k <= j; k++){
				if(g.find(s[k])==g.end()) break;
				if(k==j) ans = max(ans,j-i+1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}