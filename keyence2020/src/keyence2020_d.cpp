#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}



//反転数を求める
int inverse_number(vector<int> z){
	int cnt = 0;

	int n = z.size();
	rep(i,n){
		repr(j,n-1,i+1){
			if(z[j] < z[j-1]){
				cnt++;
				int tmp = z[j];
				z[j] = z[j-1];
				z[j-1] = tmp;
			}
		}
	}

	return cnt;
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int>> card(n,vector<int>(2));
	rep(j,2){
		rep(i,n)cin>>card[i][j];
	}

	int ans = INF;
	for (int bit = 0; bit < (1<<n); bit++){
		int count_even = 0;
		vector<P> target_even, target_odd;
		for (int i = 0; i < n; i++){
			if(bit&(1<<i)){
				count_even++;
				if(i%2==0)target_even.push_back(P(card[i][0],i));
				else target_even.push_back(P(card[i][1],i));
			}else{
				if(i%2!=0)target_odd.push_back(P(card[i][0],i));
				else target_odd.push_back(P(card[i][1],i));								
			}
		}

		if(count_even!=(n+1)/2)continue;
		sort(all(target_even));
		sort(all(target_odd));
		vector<int> target(n);
		int cur = 0;
		int pos_even=0, pos_odd=0;
		for (int i = 0; i < n; i++){
			if(i%2==0){
				target[i] = target_even[pos_even].second;
				if(cur > target_even[pos_even].first){
					cur = INF;
					break;
				}
				cur = target_even[pos_even].first;
				pos_even++;
			}else{
				target[i] = target_odd[pos_odd].second;
				if(cur > target_odd[pos_odd].first){
					cur = INF;
					break;
				}
				cur = target_odd[pos_odd].first;
				pos_odd++;
			}
		}
		if(cur==INF)continue;
		ans = min(ans,inverse_number(target));
	}

	if(ans==INF)cout<<-1<<endl;
	else cout<<ans<<endl;


	return 0;
}