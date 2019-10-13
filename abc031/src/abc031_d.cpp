#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n,k;
vector<string> v,w;
vector<int> cnt(9,0);

bool dfs(int dep){
	if(dep==k){
		map<int,string> ma;
		rep(i,n){
			int pos=0;
			rep(j,v[i].size()){
				int target = v[i][j]-'0'-1;
				if(pos+cnt[target]>w[i].size())return false;

				string t = w[i].substr(pos,cnt[target]);
				if(ma.find(target)!=ma.end() && ma[target]!=t) return false;
				ma[target]=t;
				pos+=cnt[target];
			}
			if(pos!=w[i].size())return false;
		}

		rep(i,k)cout<<ma[i]<<endl;

		return true;
	}

	rep(i,3){
		cnt[dep]=i+1;
		if(dfs(dep+1)) return true;
	}

	return false;
}


int main()
{
	cin>>k>>n;
	v.resize(n);
	w.resize(n);
	rep(i,n)cin>>v[i]>>w[i];


	dfs(0);
	
	
	return 0;
}