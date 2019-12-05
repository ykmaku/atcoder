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

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> p(n);
	rep(i,n)cin>>p[i];

	vector<int> is_sort(n,0);

	int left=0,right=0;
	while(right<n-1){
		if(p[right]>p[right+1]){
			right++;
			left=right;
		}else{
			right++;
			if(right-left+1==k)is_sort[left]=1,left++;
		}
	}
	int sorted_num = accumulate(all(is_sort),0);
	if(sorted_num>0)sorted_num--;

	// for(auto x:is_sort)cout<<x<<" ";
	// cout<<endl;

	set<int> s,rev_s;
	rep(i,k)s.emplace(p[i]),rev_s.emplace(-p[i]);
	int res=0;
	left=0,right=k-1;
	while(right<n-1){
		int max_ = *rev_s.begin()*-1;
		int min_ = *s.begin();

		if(p[left] == min_ && p[right+1]>max_ && is_sort[left]==0){
			// cout<<left+1<<" "<<p[right+1]<<endl;
			res++;
		}
		s.erase(p[left]);
		s.emplace(p[right+1]);
		rev_s.erase(-p[left]);
		rev_s.emplace(-p[right+1]);
		left++,right++;
	}

	cout<<n-k+1-sorted_num-res<<endl;

	return 0;
}