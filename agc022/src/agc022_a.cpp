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
	string s;
	string end = "zyxwvutsrqponmlkjihgfedcba";

	cin>>s;
	if(s==end){
		cout<<-1<<endl;
		return 0;
	}

	if(s.length()<26){
		int al[26] = {};
		rep(i,s.length())al[s[i]-'a']++;
		rep(i,26)if(al[i]==0){
			s+=('a'+i);
			break;
		}
		cout<<s<<endl;
		return 0;
	}else{
		int pos = -1;
		for (int i = 25; i >= 0; i--){
			if(s[i]>s[i-1]){
				pos = i-1;
				break;
			}
		}
		char ad='z';
		for (int i = pos+1; i < 26; i++){
			if(s[i]>s[pos]){
				ad = min(s[i],ad);
			}
		}
		s = s.substr(0,pos)+ad;
		cout<<s<<endl;
		return 0;
	}

	return 0;
}