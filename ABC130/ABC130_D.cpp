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
	ll n,k;
	cin>>n>>k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}

	int left=0,right=0;
	ll ans = 0;
	ll res = 0;
	while(left<n){
		if(res<k){
			if(right>=n)break;
			res+=a[right];
			right++;
		}else{
			ans += n-right +1;
			res -= a[left];
			left++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}