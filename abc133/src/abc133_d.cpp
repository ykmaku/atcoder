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

int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}

	vector<ll> x(n);
	x[0] = accumulate(all(a),0LL);
	for (int i = 2; i < n; i+=2){
		x[0] -= 2*a[i];
	}
	for (int i = 1; i < n; i++){
		x[i] = 2*a[i]-x[i-1];
	}

	cout<<x[n-1] << " ";
	for (int i = 0; i < n-1; i++){
		cout<<x[i] << (i==n-2?"":" ");
	}
	cout<<endl;
	
	return 0;
}