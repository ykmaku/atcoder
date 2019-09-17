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
	ll a,b,c;
	cin>>a>>b>>c;

	ll cnt=0;
	while(1){
		if(a%2!=0||b%2!=0||c%2!=0){
			cout<<cnt<<endl;
			break;
		}
		if(a==b&&b==c){
			cout<<-1<<endl;
			break;
		}
		ll aa = (b+c)/2;
		ll bb = (c+a)/2;
		ll cc = (a+b)/2;
		a=aa;b=bb;c=cc;
		cnt++;
	}
	return 0;
}