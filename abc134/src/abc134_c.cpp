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

	int x = *max_element(all(a));
	int second = 0;
	bool flag = false;
	for (int i = 0; i < n; i++){
		if(a[i] == x){
			if(!flag) flag = true;
			else second = x;
		}else{
			second = max(a[i],second);
		}
	}
	for (int i = 0; i < n; i++){
		if(a[i] == x) cout << second<<endl;
		else cout << x << endl;
	}

	return 0;
}