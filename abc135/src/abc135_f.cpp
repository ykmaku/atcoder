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
	// z[i] : s[i]から始まるtの部分列でsのprefixと一致するもののうち最長のものの長さ
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

P toporogical_sort(const vector<vector<int>> g){
	int n = g.size();
	vector<int> in_degree(n,0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < g[i].size(); j++){
			in_degree[g[i][j]]++;
		}
	}

	vector<int> res,length(n);
	stack<int> S;
	for(int i = 0; i < n; i++){
		if(in_degree[i]==0) S.push(i),length[i]=0;
	}

	while(!S.empty()){
		int p = S.top();
		S.pop();
		res.push_back(p);
		for(int i = 0; i < g[p].size(); i++){
			in_degree[g[p][i]]--;
			if(in_degree[g[p][i]]==0) S.push(g[p][i]),length[g[p][i]]=length[p]+1;
		}
	}

	//res.size()==nならばgはDAG
	return P(res.size(),*max_element(all(length)));
}

int main()
{
	string s,t;
	cin>>s>>t;

	int n = s.size(), m = t.size();
	string res=s;
	for (int cnt = 0; cnt < m/n; cnt++){
		res += s;
	}
	s=res;
	s += s;

	s = t + '0' + s;

	vector<int> z = z_algorithm(s);
	vector<vector<int>> g(n,vector<int>());
	set<P> edge;
	for (int i = m+1; i < s.size(); i++){
		if(z[i]==t.size()) edge.insert(P((i-(m+1))%n, (i-(m+1)+z[i])%n));
	}

	for(auto x: edge){
		g[x.first].push_back(x.second);
	}


	P ans = toporogical_sort(g);
	cout<<(ans.first==n?ans.second:-1)<<endl;


	return 0;
}