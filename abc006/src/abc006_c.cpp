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
	int n,m;
	cin>>n>>m;
	for (int i = 0; i <= n; i++){
		if(2*i+4*(n-i)==m){
			cout<<i<<" "<< 0<<" "<<n-i<<endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++){
		if(2*i+4*(n-1-i)==m-3){
			cout<<i<<" "<< 1<<" "<<(n-1)-i<<endl;
			return 0;
		}
	}
	cout<<-1<<" " << -1<< " "<<-1<<endl;
	return 0;
}