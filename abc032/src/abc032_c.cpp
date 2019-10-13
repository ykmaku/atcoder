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

int main()
{
	int n;
	ll k;
	cin>>n>>k;
	vector<ll> a(n);
	rep(i,n)cin>>a[i];

	if(*min_element(all(a))==0){
		cout<<n<<endl;
		return 0;
	}

	int left=0,right=0;
	int ans=0;
	ll res=1;
	while(left<n){
		if(right<n&&res*a[right]<=k){
			res*=a[right];
			right++;
		}else{
			if(right==left){
				right++;
				left++;
			}else{
				ans = max(ans,right-left);
				res/=a[left];
				left++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}