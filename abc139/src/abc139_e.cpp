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
	//resはトポロジカルソートされた頂点列
	//*max_element(all(length))はgの最長パスの長さ
	if(res.empty() || res.size()!=n){
		return P(-1,-1);
	}else{
		vector<int> dp(n,0);
		rep(i,n){
			int p = res[i];
			rep(j,g[p].size()){
				dp[g[p][j]] = max(dp[g[p][j]],dp[p]+1);
			}
		}

		return P(n,*max_element(all(dp)));
	}

}

int main()
{
	int n;
	cin>>n;
	vector<vector<int>> a(n,vector<int>(n-1));
	rep(i,n){
		rep(j,n-1){
			cin>>a[i][j];
		}
	}
	rep(i,n)rep(j,n-1)a[i][j]--;


	vector<vector<int>> idx(n,vector<int>(n,-1));
	int idxnum=0;
	rep(i,n)repi(j,i+1,n)idx[i][j]=idxnum,idx[j][i]==idxnum++;
	
	vector<vector<int>> g(n*(n-1)/2);
	rep(i,n){
		rep(j,n-2){
			int p=i,from=a[i][j];
			if(p>from)swap(p,from);

			int q=i,to=a[i][j+1];
			if(q>to)swap(q,to);

			int x=idx[p][from];
			int y=idx[q][to];
			g[x].push_back(y);
		}
	}

	P ans=toporogical_sort(g);
	cout<<(ans.first==n*(n-1)/2?ans.second+1:-1)<<endl;


	return 0;
}
