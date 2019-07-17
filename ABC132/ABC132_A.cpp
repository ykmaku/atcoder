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

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	string s;
	cin>>s;
	if(s[0]==s[1] && s[2]==s[3] && s[0]!=s[2]) cout<<"Yes"<<endl;
	else if(s[0]==s[2] && s[1]==s[3] && s[0]!=s[1]) cout<<"Yes"<<endl;
	else if(s[0]==s[3] && s[1]==s[2] && s[0]!=s[1]) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;


	return 0;
}