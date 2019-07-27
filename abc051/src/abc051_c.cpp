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
	int x,y,a,b;
	cin>>x>>y>>a>>b;
	// vector<string> ans;
	// for (int i = x; i < a; i++){
	// 	ans.push_back('R');
	// }
	// for (int i = y; i < b; i++){
	// 	ans.push_back('U');
	// }
	// for (int i = x; i < a; i++){
	// 	ans.push_back('L');
	// }
	// for (int i = y; i < b; i++){
	// 	ans.push_back('D');
	// }

	// ans.push_back('D');
	// for (int i = x; i < a+1; i++){
	// 	ans.push_back('R');
	// }
	// for (int i = y-1; i < b; i++){
	// 	ans.push_back('U');
	// }
	// ans.push_back('L');
	// ans.push_back('U');
	// for (int i = a; i > x-1; i--){
	// 	ans.push_back('L');
	// }
	// for (int i = b+1; i > y; i--){
	// 	ans.push_back('D');
	// }
	// ans.push_back('R');
	// for(auto c:ans)
	// 	cout<<c;
	// cout<<endl;

	int dx = a-x, dy=b-y;
	cout<<string(dx,'R') << string(dy,'U');
	cout<<string(dx,'L') << string(dy,'D');
	cout<<'D'<< string(dx+1,'R')<<string(dy+1,'U')<<'L';
	cout<<'U'<<string(dx+1,'L')<<string(dy+1,'D')<<'R'<<endl;
	
	return 0;
}