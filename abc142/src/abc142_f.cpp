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
#include <iomanip>
#include <bitset>


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
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n,vector<int>());
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
	}

	vector<int> ans;
	rep(i,n){
		queue<int> que;
		vector<int> prev(n),visited(n,0);
		que.push(i);
		visited[i]++;
		int last=-1;
		bool flag=false;
		while(!que.empty()){
			int p = que.front();que.pop();
			for(auto x:g[p]){
				if(visited[x]==0)que.push(x),prev[x]=p,visited[x]++;
				if(x==i){last=p,prev[x]=p,flag=true;}
			}
			if(flag)break;
		}
		if(last>=0){
			vector<int> path;
			set<int> s;
			int now = last;
			while (1){
				path.push_back(now);
				if(now==i)break;
				now = prev[now];
			}
			reverse(all(path));
			bool flag=true;
			for(auto v:path){
				s.insert(v);
				for(auto u:g[v]){
					if(s.count(u)>0){
						if(v==last&&u!=i) flag=false;
						if(v!=last) flag=false;
					}
				}
			}

			if(flag){
				cout<<s.size()<<endl;
				for(auto x:s)cout<<x+1<<endl;
				return 0;
			}
		}
	}
	
	cout<<-1<<endl;
	return 0;

	return 0;
}