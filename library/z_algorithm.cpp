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

vector<int> z_algorithm(string s){
	// z[i] : s[i]から始まるsの部分列でsのprefixと一致するもののうち最長のものの長さ
	int n = s.length();
	vector<int> z(n,0);

	int l=0,r=0;
	z[0] = n;
	for (int i = 1; i < n; i++){
		if(i>r){
			l=i,r=i;
			while(r<n && s[r]==s[r-l]) r++;
			z[i]=r-l;
			r--;
		}else{
			int k = i-l;
			if(z[k]<r-i+1){
				z[i]=z[k];
			}else{
				l=i;
				while(r<n && s[r]==s[r-l]) r++;
				z[i]=r-l;
				r--;
			}
		}
	}
	return z;
}

int main()
{	
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0;
	for (int i = 0; i < n; i++){
		string t = s.substr(i,n-i);
		vector<int> z = z_algorithm(t);

		for (int j = i+1; j < n; j++){
			if(z[j-i]<=j-i && z[j-i]>=ans) ans=z[j-i];
		}
	}
	cout<<ans<<endl;

	return 0;
}