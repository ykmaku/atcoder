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
	int n;
	cin>>n;
	set<int>ans;
	if(n==3){
		ans = {2,5,63};
	}else if(n==4){
		ans={2,5,20,63};
	}else if(n==5){
		ans={2,5,20,30,63};
	}else{
		ans={2,3,4};
		n -= 3;
		for (int x = 6; x <= 30000; x++){
			if(x%6==1||x%6==5) continue;
			ans.insert(x);
			n--;
			if(n==0)break;
		}
		int sum = accumulate(all(ans),0);
		if(sum%6==2){
			ans.erase(8);
			ans.insert(30000);
		}else if(sum%6==3){
			ans.erase(9);
			ans.insert(30000);
		}else if(sum%6==5){
			ans.erase(9);
			ans.insert(30000-2);
		}
	}

	for(auto x:ans)cout<<x<<" ";
	cout<<endl;
	return 0;
}