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

#define rep(i,n) for(int i=0;i<(n);++i)
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
	set<int> ng;
	rep(i,3){
		int x;
		cin>>x;
		ng.insert(x);
		if(x==n){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	bool flag = true;
	rep(i,100){
		if(ng.find(n-3)==ng.end()&&n-3>=0) n -= 3;
		else if(ng.find(n-2)==ng.end() && n-2>=0) n -= 2;
		else if(ng.find(n-1)==ng.end() && n-1>=0) n -= 1;
		else flag = false;
		if(n==0) break;
	}
	if(n!=0)flag = false;
	
	cout<<(flag?"YES":"NO")<<endl;
	
	return 0;
}