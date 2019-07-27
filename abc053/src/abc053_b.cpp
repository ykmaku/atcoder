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
	string s;
	cin>>s;
	int left,right;
	for (int i = 0; i < s.size(); i++){
		if(s[i] == 'A'){
			left=i;
			break;
		}
	}
	for (int i = s.size()-1; i >= 0; i--){
		if(s[i]=='Z'){
			right=i;
			break;
		}
	}
	cout<<right-left+1<<endl;
	return 0;
}