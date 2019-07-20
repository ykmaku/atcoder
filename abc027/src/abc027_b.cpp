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
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}
	int sum = accumulate(all(a),0);
	if(sum%n!=0){
		cout<<-1<<endl;
		return 0;
	}
	int ans = 0;
	int cnt = 0;
	int sum2 = 0;
	int pos = 0;
	while(pos<n){
		for (int i = pos; i < n; i++){
			sum2 += a[i];
			cnt++;
			if(sum2%cnt==0 && sum2/cnt == sum/n){
				sum2 = 0;
				cnt = 0;
				pos = i+1;
			}else{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}