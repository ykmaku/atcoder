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

vector<int> prime(int x){
	vector<int> ret;
	for (int i = 1; i*i <= x; i++){
		if(x%i==0){
			ret.push_back(i);
			if(x/i!=i) ret.push_back(x/i);
		}
	}
	return ret;
}

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}

	int sum = accumulate(all(a),0);
	vector<int> div = prime(sum);

	int ans = 1;
	for(auto x : div){
		vector<int> modulo_x = a;
		for (int i = 0; i < n; i++){
			modulo_x[i] %= x;
		}
		sort(all(modulo_x));

		vector<int> sum(n+1,0);
		for (int i = 1; i <= n; i++){
			sum[i] = sum[i-1] + modulo_x[i-1];
		}

		for (int i = 1; i <= n; i++){
			if(sum[i] == (n-i)*x - (sum[n]-sum[i]) && sum[i]<=k) ans = max(ans,x);
		}
	}
	cout<<ans<<endl;
	return 0;
}