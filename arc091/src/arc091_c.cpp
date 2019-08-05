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
	int n,a,b;
	cin>>n>>a>>b;
	if(a+b<=n+1 && a*b>=n){
		if(b-1==0){
			for (int j = 1; j <= n; j++){
				cout<<j<<" ";
			}cout<<endl;
			return 0;
		}
		vector<int> ans;
		int right = a+b-2;  //
		for (int j = right+1; j <= n; j++){
			ans.push_back(j);
		}
		for (int j = right; j >= a+1; j--){
			ans.push_back(j);
		}
		for (int j = 1; j <= a; j++){
			ans.push_back(j);
		}
		for(auto x:ans) cout<<x<<" ";
		cout<<endl;
	}else{
		cout<<-1<<endl;
	}
	return 0;
}