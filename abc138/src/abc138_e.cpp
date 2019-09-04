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
	string s,t;
	cin>>s>>t;

	map<char,set<int>> mp;
	rep(i,s.size()){
		mp[s[i]].insert(i);
	}
	ll cnt = 0;
	int pos = -1;
	ll res = 0;
	rep(i,t.size()){
		if(mp[t[i]].empty()){
			cout<<-1<<endl;
			return 0;
		}
		auto it = mp[t[i]].upper_bound(pos);
		if(it == mp[t[i]].end()){
			cnt++;
			pos=-1;
			it = mp[t[i]].upper_bound(pos);
		}
		pos = *it;
		res = *it+1;
	}

	cout<<cnt*(ll)s.size()+res<<endl;


	return 0;
}