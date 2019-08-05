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
	vector<int> h(n);
	for (int i = 0; i < n; i++){
		cin>>h[i];
	}
	int now = h[n-1];
	for (int i = n-2; i >= 0; i--){
		if(h[i]>h[i+1]+1){
			cout<<"No"<<endl;
			return 0;
		}else if(h[i] == h[i+1]+1){
			h[i]--;
		}
		now = h[i];
	}
	cout<<"Yes"<<endl;
	return 0;
}