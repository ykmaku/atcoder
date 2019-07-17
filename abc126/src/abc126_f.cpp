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
	int m,k;
	cin>>m>>k;
	ll p = 1;
	for(int i = 1; i <= m; i++){
		p *= 2LL;
	}
	if(p <= k){
		cout<<-1<<endl;
		return 0;
	}
	if(m==1){
		if(k==0){
			printf("%d %d %d %d\n", 0,0,1,1);
		}else{
			cout<<-1<<endl;
		}
		return 0;
	}

	deque<ll> ans;
	ans.push_front(k);
	for(int i = 0; i < p; i++){
		if(i!=k){
			ans.push_back(i);
			ans.push_front(i);
		}
	}
	ans.push_front(k);
	for(auto v : ans)
		cout<<v<<" ";
	printf("\n");
	return 0;
}