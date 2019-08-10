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
	vector<vector<string>> c(4,vector<string>(4));
	for (int j = 0; j < 4; j++){
		for (int k = 0; k < 4; k++){
			cin>>c[j][k];
		}
	}
	for (int j = 3; j >= 0; j--){
		for (int k = 3; k >= 0; k--){
			cout<<c[j][k]<<" ";
		}cout<<endl;
	}


	return 0;
}