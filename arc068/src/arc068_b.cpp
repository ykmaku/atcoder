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
	sort(all(a));
	int mi=-1,ma=-1;
	int cnt = 0;
	for (int i = 1; i < n; i++){
		if(a[i-1]==a[i]){
			cnt++;
		}
	}

	if(cnt%2==0)cout<<n-cnt<<endl;
	else cout<<n-cnt-1<<endl;

	return 0;
}