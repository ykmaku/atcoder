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
#include <bitset>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()int s = 0;


const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	int s = 3;
	cout<< "s = "<<bitset<8>(s)<<endl;
	rep(i,5)cout<<bitset<8>(i)<<" "<<bitset<8>(s&(1<<i))<<" "<<(s&(1<<i)==0?"true":"false")<<endl;
	return 0;
}