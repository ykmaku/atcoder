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
	string s,t;
	cin>>s>>t;
	int pos = -1;
	for (int i = 0; i <= s.size()-t.size(); i++){
		if(i+t.size()-1>s.size()-1) break;
		for (int j = 0; j < t.size(); j++){
			if(!(s[i+j] == t[j] || s[i+j] == '?')) break;
			if(j==t.size()-1){
				pos = i;
			}
		}
	}

	if(pos>=0){
		for (int j = 0; j < t.size(); j++) s[pos+j] = t[j];
		for (int i = 0; i < s.size(); i++){
			if(s[i]=='?') s[i] = 'a';
		}
		cout<<s<<endl;
	}else{
		cout<<"UNRESTORABLE"<<endl;
	}
	
	return 0;
}